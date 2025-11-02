# DDA raycasting cheat sheet

Variables (per ray):
- posX, posY: player position (floats), mapX=(int)posX, mapY=(int)posY.
- rayDirX, rayDirY: ray direction (not necessarily normalized).
- deltaDistX = |1 / rayDirX| (if rayDirX == 0 → big number)
- deltaDistY = |1 / rayDirY| (if rayDirY == 0 → big number)
- stepX = rayDirX < 0 ? -1 : +1
- stepY = rayDirY < 0 ? -1 : +1
- sideDistX = (stepX > 0 ? (mapX + 1.0 - posX) : (posX - mapX)) * deltaDistX
- sideDistY = (stepY > 0 ? (mapY + 1.0 - posY) : (posY - mapY)) * deltaDistY

Loop (advance to next grid boundary):
1. if sideDistX < sideDistY:
   - sideDistX += deltaDistX
   - mapX += stepX
   - side = 0 (hit a vertical grid line)
2. else:
   - sideDistY += deltaDistY
   - mapY += stepY
   - side = 1 (hit a horizontal grid line)
3. Stop when map[mapY][mapX] is a wall.

Perpendicular distance (for correct wall height):
- if side == 0:
  - perpDist = ((mapX - posX) + (1 - stepX) / 2.0) / rayDirX
- else:
  - perpDist = ((mapY - posY) + (1 - stepY) / 2.0) / rayDirY
- Use fabs or guard against 0 to avoid division errors; clamp very small values.

Project to screen (height in pixels):
- lineHeight = (int)(screenHeight / perpDist)
- draw vertical line centered at screenHeight/2 from y0 to y1:
  - y0 = -lineHeight/2 + screenHeight/2
  - y1 =  lineHeight/2 + screenHeight/2

FOV and rayDir per screen column:
- dir = (cos(playerAngle), sin(playerAngle))
- plane = perpendicular to dir, scaled by tan(FOV/2)
- camX in [-1..1] across screen
- rayDir = dir + plane * camX

Common pitfalls:
- Forgetting to use perpendicular distance (fish-eye distortion).
- Division by zero for rayDirX/Y = 0 → use large sentinel for deltaDist or guard.
- Player starting inside a wall.
- Using pixel_put per pixel (slow). Prefer image buffer, then put the image once per frame.
