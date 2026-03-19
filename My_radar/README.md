#  My Radar - Air Traffic Simulation

## Description
My Radar is a 2D graphical simulation of an air traffic control system. It handles the movement of multiple planes and their interaction with towers and protection zones in real-time.

## Key Technical Skills
* **Graphical Rendering:** Managing frame rates and hardware-accelerated 2D graphics with CSFML.
* **Collision Detection:** Implementing efficient algorithms (like Quadtrees) to detect plane collisions.
* **Mathematics:** Using vectors for plane movements and calculating angles/distances.


##  Constraints & Rules
* **Hitboxes:** Every plane has a hitbox. If two hitboxes touch, they collide (unless in a tower zone).
* **Control Areas:** Towers have a circular "safe zone". Planes inside these zones cannot collide.
* **Performance:** The simulation must stay fluid (60 FPS) even with hundreds of planes on screen.
* **Toggles:** Use 'L' to show/hide hitboxes and 'S' to show/hide sprites.

##  Bonus Features
I have implemented several advanced features to enhance the simulation:
* **Random Hitboxes (`-r`)**: Sets random plane hitbox sizes (between 50 and 70 square pixels).
* **Storm System (`-s[NUMBER]`)**: Generates a specific number of storms on the map.
* **Plane Counter**: A real-time display to track active aircraft.
* **Music Management**: Audio system integration for better immersion.

## How to Use

### 1. Compilation
Use the provided Makefile to compile the project:
* In a terminal: `make`

### 2. Execution
The program requires a configuration file:
* In a terminal: `./my_radar [path_to_script_file]`
* In a termianl: `./my_radar -h` for all features.
* The script file contains the positions of planes (`A`) and towers (`T`).
