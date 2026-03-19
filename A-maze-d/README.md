#  A-maze-d - Maze Solver

## Description
A-maze-d is a pathfinding project developed at Epitech. The objective is to find the most efficient route for multiple "robots" to traverse a maze from a starting point (entry) to an ending point (exit).
The project requires parsing a specific file format containing the maze structure and handling potential collisions between robots.

## Key Technical Skills
* **Graph Theory:** Representing the maze as a collection of nodes and edges (rooms and tunnels).
* **Pathfinding Algorithms:** Implementation of optimized search algorithms (like Dijkstra or BFS) to find the shortest path.
* **Data Parsing:** Robust handling of standard input to extract maze dimensions, robot counts, and connections.
* **Flow Management:** Coordinating the movement of multiple entities through restricted paths.

---

##  Constraints & Rules
To successfully complete the maze, the program must follow these strict rules:
* **One by One:** Robots move room by room.
* **Single Occupancy:** Each room can contain only **one robot at a time** (to avoid collisions).
* **Exceptions:** The `##start` (entry) and `##end` (exit) rooms can contain an unlimited number of robots simultaneously.
* **Efficiency:** All robots must reach the exit in the fewest possible steps.

---

## How to Use

### 1. Compilation
Use the provided Makefile to compile the project:
*  -In a treminal `make`
### 2. Execution
The program reads the maze configuration from the standard input. You must provide a maze file as an argument using a redirection:
*  -In a terminal `./amazed < [path_to_map_file]`
*  -The program will then output the movements of each robot step-by-step (ex: P1-2 P2-3), ensuring that no two robots occupy the same room at the same time (except for the entry and exit).
