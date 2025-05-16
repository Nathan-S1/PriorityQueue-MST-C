# PriorityQueue-MST-C
PriorityQueue and MST in C++

## Author  
Nathan Shorez  

---

## Project Overview  
This project implements a Priority Queue and Prim’s Minimum Spanning Tree (MST) algorithm using C++. The objective is to find the most efficient set of links between vertices in a graph without creating unnecessary cycles, minimizing the overall cost of connecting all vertices.

---

## What is a Minimum Spanning Tree?  
A Minimum Spanning Tree (MST) is a subset of edges in a connected graph that connects all vertices without forming cycles and with the minimum possible total edge weight. Essentially, it connects all points in the most efficient manner without redundancy.

---

## Real-World Applications of MST  
- **Network Cabling:** Reducing cable length while connecting all network nodes.  
- **Circuit Design:** Minimizing the connections between circuit components while maintaining a complete circuit.  
- **Transportation Planning:** Creating the shortest routes between multiple destinations.  

---

## Matrix Used  

```cpp
int customGraph[8][8] = {
    {0, 2, 0, 6, 0, 16, 0, 1},
    {2, 0, 3, 8, 5, 0, 8, 0},
    {0, 3, 0, 13, 7, 0, 15, 0},
    {6, 8, 13, 0, 9, 14, 0, 11},
    {0, 5, 7, 9, 0, 4, 0, 0},
    {16, 0, 0, 14, 4, 0, 10, 0},
    {0, 8, 15, 0, 0, 10, 0, 12},
    {1, 0, 0, 11, 0, 0, 12, 0}
};
```

---

## Sample Output  

```
Prim's MST is Edge -> Cost
0 - 7 -> 1
0 - 1 -> 2
1 - 2 -> 3
1 - 4 -> 5
4 - 5 -> 4
0 - 3 -> 6
1 - 6 -> 8
```

---

## How to Compile and Run  

1. **Compile the source code:**

```bash
g++ src/PriorityQueueMST.cpp -o mst
```

2. **Run the program:**

```bash
./mst
```

---

## Dependencies  
- C++ Compiler (e.g., g++)

---
