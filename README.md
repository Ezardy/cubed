# Cub3D - 2.5D game written in C
| Tech Demo | Pools | Backrooms |
|---|---|---|
| <img src="https://github.com/user-attachments/assets/e1cfa781-500a-46c3-be46-67e554d02e2d"> | <img src="https://github.com/user-attachments/assets/0ea4cf81-1d05-44bd-9bce-9a48a62ed41a"> | <img src="https://github.com/user-attachments/assets/d5f40d8e-c302-4b3a-bb79-536172746db9"> |

https://youtu.be/ZokfOj6_uo4
## Features
* Any Detph Transparency
* Minimap
* Customizable Ceil and Floor Colors
* Customizable Wall Textures
* Door Animations
* Wall Collisions
* Mouse Camera Rotation
## Usage
```
cub3D path/to/map
```
## Map Configuration
Example of a map:
```
NO textures/pool.xpm
SO textures/pool.xpm
WE textures/pool.xpm
EA textures/pool.xpm
C 212,228,240
F 7,136,229

11111111111
10010000001
10010000001
10010000001
100D00W0001
10010000001
10010000001
11111111111
```
* NO, SO, WE, EA - sides of walls
* textures/pool.xpm - .xpm texture of a wall side. rgb(0,0,0) is considered as transparent
* C - ceil color in RGB (0-255)
* F - floor color in RGB
* 1 - wall
* 0 - empty space
* D - door, must have adjacent walls (1)
* W - player looks towards West. Other options: E, S, N
