#include "cmm.H"
int main(){
    //DIRECTED GRAPH G1 (as an adjacency list)
    let G1 = {
        /*0*/        {{1,4},{7,8}},   
        /*1*/        {{0,4}, {2,8}, {7,11}},
        /*2*/        {{1,8},{8,2},{5,4},{3,7}},
        /*3*/        {{2,7},{4,9},{5,14}},
        /*4*/        {{3,9},{5,10}},
        /*5*/        {{2,4},{3,14},{4,10},{6,2}},
        /*6*/        {{5,2},{7,1},{8,6}},
        /*7*/        {{0,8},{1,11},{6,1},{8,7}},
        /*8*/        {{2,2},{6,6},{7,7}}
    };

    _ seq = range(len(G1)), V = seq | $(i) {   //"For each i in seq, initialize {inf, -1}."
            return {inf, -1};                   // Initialize vertex array for Prim's algorithm
        };

    _ Q = heap(seq | $(i){return {inf, i}; }); // priority Q[priority,index]

    let s = 0; // Set the source vertex

    V[s][0] = 0;  // Set the distance component of the source vertex as 0

    // Only the source vertex has distance 0, all others are infinity 
    Q.heapUpdate(V[s][0], s); // Update priority queue with starting vertex


    while (len(Q) > 0)
    {
        _ u = (--Q)[1];  // Pop the vertex with the smallest weight (priority)

        // Print the current vertex being processed and its parent
        if (V[u][1] != -1) { // Don't print the root's connection
            print("Added edge (", V[u][1], " to ", u, "), weight = ", V[u][0]);
        }

        // For each (v, w) in the adjacency list of u, process edges
        G1[u] | $(v, w)  
        {   
            if(w < V[v][0]) // If a better (smaller) edge weight is found
            {
                V[v][1] = u; // Update the parent of vertex v
                V[v][0] = w; // Update the distance (weight of the edge)
                Q.heapUpdate(V[v][0], v); // Update Priority Queue
            }
            yield;  // Continue processing
        };
    }

    print("\nFinal Minimum Spanning Tree (MST):");
    for ( _[i, x]: V)
    {
        //if (x[1] != -1) { // Skip the source vertex since it has no parent
            print("Vertex ", i, " is connected to Vertex ", x[1], " with edge weight ", x[0]);
        //}
    }
    
    return 0;
}
