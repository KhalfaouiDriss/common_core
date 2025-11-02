# DDA animation (GLSL Canvas)

This folder includes `dda_anim.frag`, a fragment shader that animates the DDA stepping across a small 5×5 grid.

What you’ll see:
- A centered 5×5 grid with border walls.
- A player dot at pos=(2.5, 2.5).
- A ray that slowly sways from horizontal to slight diagonal.
- Cells visited by the DDA steps are highlighted (yellow), and the current stepped-to cell glows.
- The ray line is drawn from the player towards the current step.

## How to run it
1. Install the “GLSL Canvas” VS Code extension (if you haven’t already).
2. Open `docs/dda_anim.frag` in the editor.
3. Use the GLSL Canvas command/panel to render the shader. It should start animating automatically using the built-in time uniform.

The shader supports both `u_resolution/u_time` and `iResolution/iTime` uniform names for compatibility.

## Tweak ideas
- Make the ray purely horizontal: set `ang = 0.0` in the shader.
- Increase stepping speed: change `stepsToShow = int(mod(floor(t * 2.0), float(maxSteps)));` (increase the multiplier).
- Visualize hit cell differently: treat `mapAt(cur)==1` and color `last` cell in red.
- Change map size: edit `MAP_W/H` and adjust walls in `mapAt`.

## Relation to code
- `deltaDistX = |1/rayDirX|`, `deltaDistY = |1/rayDirY|`
- `sideDistX/Y` initialized to the distance to the next grid boundary along X/Y.
- Each frame increments whichever `sideDist` is smaller; the corresponding `mapX`/`mapY` changes by `stepX/stepY`.
- Stops/hits on a wall cell (here: border walls).

Also see:
- `DDA_frames.excalidraw` and `DDA_diagonal_frames.excalidraw` for storyboard views.
- `DDA_cheatsheet.md` for formulas and common pitfalls.
