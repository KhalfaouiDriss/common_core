// raycast.c
// Enable POSIX features for clock_gettime/nanosleep declarations
#define _POSIX_C_SOURCE 200809L
// Minimal ASCII raycaster in plain C (POSIX). Compile with:
//   gcc -O2 -std=c11 raycast.c -lm -o raycast
//
// Controls (while running in terminal):
//   W - move forward
//   S - move backward
//   A - rotate left
//   D - rotate right
//   Q - quit

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <termios.h>
#include <string.h>
#include <time.h>

// Provide M_PI if not defined by math.h
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define MAP_W 24
#define MAP_H 24
#define SCREEN_W 120
#define SCREEN_H 40

static const char *mapData =
"########################"
"#..............##......#"
"#..##...........#......#"
"#...............#......#"
"#.......##......#......#"
"#...............#......#"
"#...............#......#"
"#..##...........#......#"
"#..##...........#......#"
"#...............#......#"
"#...............#......#"
"#...............#......#"
"#...............#......#"
"#......##.............##"
"#......##.............##"
"#...............#......#"
"#...............#......#"
"#...............#......#"
"#...............#......#"
"#...............#......#"
"#...............#......#"
"#......................#"
"#......................#"
"########################";

struct termios orig_termios;

void disableRawMode() {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

void enableRawMode() {
    tcgetattr(STDIN_FILENO, &orig_termios);
    atexit(disableRawMode);
    struct termios raw = orig_termios;
    raw.c_lflag &= ~(ECHO | ICANON); // no echo, non-canonical
    raw.c_cc[VMIN] = 0;
    raw.c_cc[VTIME] = 0;
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

int map_at(int x, int y) {
    if (x < 0 || x >= MAP_W || y < 0 || y >= MAP_H) return '#';
    return mapData[y * MAP_W + x];
}

int main() {
    // Player
    double px = 12.0, py = 12.0; // start roughly in center
    double pa = 0.0;             // player angle (radians)
    double fov = M_PI / 3.0;     // 60 degrees
    double moveSpeed = 5.0;      // units per second
    double rotSpeed = 2.5;       // radians per second

    char *screen = malloc(SCREEN_W * SCREEN_H + 1);
    if (!screen) {
        perror("malloc");
        return 1;
    }

    enableRawMode();

    struct timespec last_time;
    clock_gettime(CLOCK_MONOTONIC, &last_time);

    printf("\x1b[2J"); // clear screen
    while (1) {
        // Timing
        struct timespec cur_time;
        clock_gettime(CLOCK_MONOTONIC, &cur_time);
        double elapsed = (cur_time.tv_sec - last_time.tv_sec) + (cur_time.tv_nsec - last_time.tv_nsec) / 1e9;
        last_time = cur_time;

        // Input (non-blocking)
        char c = 0;
        ssize_t n = read(STDIN_FILENO, &c, 1);
        if (n > 0) {
            if (c == 'q' || c == 'Q') break;
            if (c == 'a' || c == 'A') {
                pa -= rotSpeed * elapsed;
            } else if (c == 'd' || c == 'D') {
                pa += rotSpeed * elapsed;
            } else if (c == 'w' || c == 'W') {
                double nx = px + cos(pa) * moveSpeed * elapsed;
                double ny = py + sin(pa) * moveSpeed * elapsed;
                // simple collision: only move if not hitting wall
                if (map_at((int)nx, (int)py) == '.') px = nx;
                if (map_at((int)px, (int)ny) == '.') py = ny;
            } else if (c == 's' || c == 'S') {
                double nx = px - cos(pa) * moveSpeed * elapsed;
                double ny = py - sin(pa) * moveSpeed * elapsed;
                if (map_at((int)nx, (int)py) == '.') px = nx;
                if (map_at((int)px, (int)ny) == '.') py = ny;
            }
        }

        // Render scene
        for (int x = 0; x < SCREEN_W; x++) {
            // For each vertical slice, compute ray angle
            double rayAngle = (pa - fov / 2.0) + ((double)x / (double)SCREEN_W) * fov;
            // Unit vector for ray in player space
            double rayX = cos(rayAngle);
            double rayY = sin(rayAngle);

            // DDA initialization
            double distanceToWall = 0.0;
            int hitWall = 0;
            int boundary = 0;

            double stepSize = 0.05; // increment size for ray (small -> more precise)
            while (!hitWall && distanceToWall < 30.0) {
                distanceToWall += stepSize;
                int testX = (int)(px + rayX * distanceToWall);
                int testY = (int)(py + rayY * distanceToWall);

                // Test if ray is out of bounds
                if (testX < 0 || testX >= MAP_W || testY < 0 || testY >= MAP_H) {
                    hitWall = 1;
                    distanceToWall = 30.0; // set max distance
                } else {
                    if (map_at(testX, testY) == '#') {
                        hitWall = 1;

                        // To give a boundary effect: sample corners to detect whether ray hits near an edge
                        double blockMidX = (double)testX + 0.5;
                        double blockMidY = (double)testY + 0.5;
                        double vx = (px + rayX * distanceToWall) - blockMidX;
                        double vy = (py + rayY * distanceToWall) - blockMidY;
                        double d = sqrt(vx*vx + vy*vy);
                        double epsilon = 0.01;
                        if (d - 0.5 < epsilon) boundary = 1;
                    }
                }
            }

            // Calculate distance to projection plane and line height
            int lineHeight = (int)((double)SCREEN_H / distanceToWall);

            int ceiling = (SCREEN_H / 2) - (lineHeight / 2);
            int floor = SCREEN_H - ceiling;

            for (int y = 0; y < SCREEN_H; y++) {
                int idx = y * SCREEN_W + x;
                if (y <= ceiling) {
                    screen[idx] = ' ';
                } else if (y > ceiling && y <= floor) {
                    // Wall shading based on distance
                    char shade;
                    if (boundary) shade = ' '; // boundary -> dark
                    else if (distanceToWall <= 2.0) shade = '#';
                    else if (distanceToWall < 4.0) shade = 'X';
                    else if (distanceToWall < 6.0) shade = 'x';
                    else if (distanceToWall < 10.0) shade = '.';
                    else shade = ' ';
                    screen[idx] = shade;
                } else {
                    // Floor shading - simple gradient by y
                    double b = 1.0 - (((double)y - SCREEN_H / 2.0) / (SCREEN_H / 2.0));
                    char floorShade;
                    if (b < 0.25) floorShade = '#';
                    else if (b < 0.5) floorShade = 'x';
                    else if (b < 0.75) floorShade = '.';
                    else if (b < 0.9) floorShade = '-';
                    else floorShade = ' ';
                    screen[idx] = floorShade;
                }
            }
        }

        // Draw mini map + player marker at top-left
        for (int my = 0; my < MAP_H; my++) {
            for (int mx = 0; mx < MAP_W; mx++) {
                int sx = mx;
                int sy = my;
                if (sx >= 0 && sx < SCREEN_W && sy >= 0 && sy < SCREEN_H) {
                    char ch = map_at(mx, my);
                    screen[sy * SCREEN_W + sx] = ch;
                }
            }
        }
        // Player on mini map
        int pmapx = (int)px;
        int pmapy = (int)py;
        if (pmapx >= 0 && pmapx < SCREEN_W && pmapy >= 0 && pmapy < SCREEN_H)
            screen[pmapy * SCREEN_W + pmapx] = 'P';

        // Null-terminate and write to terminal
        screen[SCREEN_W * SCREEN_H] = '\0';
        printf("\x1b[H"); // move cursor to top-left
        for (int y = 0; y < SCREEN_H; y++) {
            fwrite(screen + y * SCREEN_W, 1, SCREEN_W, stdout);
            putchar('\n');
        }
        printf("X=%.2f Y=%.2f Angle=%.2f  (W/S forward/back, A/D rotate, Q quit)\n", px, py, pa);

        fflush(stdout);

    // tiny sleep to cap framerate (~30ms)
    struct timespec req;
    req.tv_sec = 0;
    req.tv_nsec = 30 * 1000 * 1000; // 30ms
    nanosleep(&req, NULL);
    }

    disableRawMode();
    free(screen);
    printf("\nExited.\n");
    return 0;
}