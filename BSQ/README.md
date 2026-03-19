#  BSQ - Biggest Square Finder

## Description
BSQ (Biggest Square) is an algorithmic project focused on performance. The goal is to find the largest possible square area in a grid filled with obstacles. The program must be able to process very large maps in a minimal amount of time.

## Key Technical Skills
* **Dynamic Programming:** Implementation of an optimized algorithm to find the square in a single pass through the grid.
* **Memory Management:** Efficiently loading and storing large maps in the heap to avoid stack overflows.
* **High-Performance I/O:** Using low-level system calls (like `read`) to handle massive data input quickly.



##  Constraints & Rules
* **Map Format:** The map consists of `.` (empty) and `o` (obstacle).
* **Output:** The map must be printed with the largest square replaced by `x` characters.

## How to Use

### 1. Compilation
Use the provided Makefile to compile the project:
* In a terminal: `make`

### 2. Execution
The program takes a map file as an argument or a patern for generating a map:
* In a terminal: `./bsq [path_to_map_file]` or `./bsq "..o.."` (patern example)
* The program will output the map with the biggest square marked with `x`.
