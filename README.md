# Amazed

Amazed is a C project designed to simulate a scenario where a certain number of robots need to traverse through various rooms to reach the exit, ensuring each room is visited by only one robot at a time. The objective is to reach the exit with the fewest possible moves, utilizing BFS's algorithm for pathfinding.

## Input Format
```
#number_of_robots
<Number of robots>
#rooms
<Room IDs separated by spaces>
##start
<Start room ID coordinates>
##end
<End room ID coordinates>
<Room connections>
#tunnels
<Tunnel connections between rooms>
#moves
<Moves made by robots>
```
### Example
```
B-CPE-200> ./amazed < labyrinth
#number_of_robots
3
#rooms
2 5 0
##start
0 1 2
##end
1 9 2
3 5 4
#tunnels
0-2
0-3
2-1
3-1
2-3
#moves
P1-2 P2-3
P1-1 P2-1 P3-2
P3-1
```

## Usage
Compile the program using a C compiler, such as GCC. Create an input file named "labyrinth" in the specified format. Run the program, providing the input file as input.

```bash
make
./amazed < labyrinth
```

## Features
- Utilizes BFS's algorithm for optimal pathfinding.
- Ensures each room is visited by only one robot at a time.
- Calculates the shortest path for robot to reach the exit.
- Input file specifies the number of robots, rooms, room connections, tunnels, and moves made by robots.

## Visual Rendering
Using ncurse C library me and my team were able to generate a more visual rendering than the simple output shown above
<img src="bonus_demo.gif" alt="Visual Rendering">
