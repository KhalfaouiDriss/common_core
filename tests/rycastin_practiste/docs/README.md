# DDA storyboard diagrams

This folder contains Excalidraw diagrams you can open directly in VS Code (with the Excalidraw extension) to visualize how the DDA algorithm progresses.

## Files
- `DDA_vision.excalidraw` — A single-scene diagram showing the setup for a horizontal ray (rayDir = (1,0)) from pos = (2.5, 2.5), with sideDistX and deltaDistX annotated and the first wall hit highlighted.
- `DDA_frames.excalidraw` — A 3-frame storyboard showing the sequence:
  1. Frame 1 — Start: compute sideDistX, deltaDistX, initial mapX = 2, mapY = 2.
  2. Frame 2 — First step: sideDistX += deltaDistX, mapX -> 3 (empty).
  3. Frame 3 — Second step: sideDistX += deltaDistX, mapX -> 4 (wall) → hit.
- `DDA_diagonal_frames.excalidraw` — Multi-frame diagonal ray example (rayDir = (1, 0.5)) showing alternating X and Y steps, with concrete numbers: deltaDistX=1, deltaDistY=2, sideDistX=0.5, sideDistY=1.0 at start.
- `DDA_cheatsheet.md` — Text reference of variables, formulas, loop rules, perpendicular distance, screen projection, and common pitfalls.

## How to open
1. Open the file from the Explorer in VS Code.
2. The Excalidraw canvas will render. You can move, resize and edit elements freely.

## Step-by-step (quick reference)
Given pos=(2.5,2.5) and rayDir:
1. mapX=(int)posX=2, mapY=(int)posY=2
2. deltaDistX=|1/rayDirX|, deltaDistY=|1/rayDirY|
3. stepX = rayDirX<0 ? -1 : +1; stepY = rayDirY<0 ? -1 : +1
4. sideDistX = (stepX>0 ? (mapX+1-posX) : (posX-mapX)) * deltaDistX
   sideDistY = (stepY>0 ? (mapY+1-posY) : (posY-mapY)) * deltaDistY
5. Loop: compare sideDistX vs sideDistY to step X or Y; add deltaDist to the chosen sideDist; update mapX/mapY; stop on wall.
6. Perpendicular distance (no fish-eye):
   - side==0 → perpDist=((mapX-posX)+(1-stepX)/2)/rayDirX
   - side==1 → perpDist=((mapY-posY)+(1-stepY)/2)/rayDirY
7. Project: lineHeight=screenH/perpDist, draw from y0=-lineHeight/2+screenH/2 to y1=+lineHeight/2+screenH/2.

## Ideas to extend
- Duplicate the frames and create a diagonal ray example (rayDir = (1, 0.5)) to show alternating X/Y steps with sideDistX vs sideDistY comparisons.
- Add notes about `perpDist` (perpendicular wall distance) used for correct wall heights.
- Show how FOV casts many rays across the screen to form a single frame in your renderer.
