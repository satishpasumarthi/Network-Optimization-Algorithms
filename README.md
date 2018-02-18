# Network-Optimization-Algorithms
This project was a part of "Analysis of Algorithms" course (CSCE-629) under Dr. Jianer Chen 

### Problem statement

**Maximum Bandwidth path problem:**  Given a source node 's' and a destination
node 't' in a network G, in which each edge 'e' is associated with a value
w(e), construct a path from 's' to 't' in G whose bandwidth is maximized (the
bandwidth of a path is equal to the minimum edge bandwidth over all edges in
the path).

**Alogithms used**
The approach to the Maximum-Bandwidth-Path problem involved implementation of following algorithms and their runtime comparisions.
- Dijkstra’s Algorithm 
- Modified Dijkstra’s Algorithm using Max-Heap
- Modified Kruskal's Algorithm using Make_set-Union-Find


The report discusses the implementation and the results of the implementation of these three  algorithms on two types of graphs:  
- **Sparse Graph** – Graph with 5000 vertices for which the average vertex degree is chosen as 8. The graph edges have been assigned random positive weights.  
- **Dense Graph** – Graph with 5000 vertices in which each vertex is adjacent to about 20% of the other vertices, which are randomly chosen using Erdős-Rényi model, the details of which are explained in the report. The edges have been assigned random positive weights.  In the process of the implementation, I created various other data structures, such as:  

### How to run
1.You should see a Makefile:  
%make clean  
%make all  
2. The above step will create a runme file which is a binary executable.
3. Run time as well as the paths of max-bw will be displayed on the stdout
