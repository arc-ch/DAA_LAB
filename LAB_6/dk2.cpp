#include "cmm.H"
int main(){

    //DIRECTED GRAPH G1
    let G1 = {
        /*0*/        {{1, 10}, {3, 5}},   // 0 connects to 1 with weight 10, 3 with weight 5
        /*1*/        {{2, 1}, {3, 2}},
        /*2*/        {{4, 4}},
        /*3*/        {{1, 3}, {2, 9}, {4, 2}},
        /*4*/        {{0, 7}, {2, 6}}
    };
    
    _ seq = range(len(G1)), V = seq | $(i) { return {inf, -1}; };
    _ Q = heap(seq | $(i){ return {inf, -i}; }); // priority queue, sorted by distances

    let s = 0; // set the source vertex

    V[s][0] = 0;  // set the distance component of the source vector as 0

    // Initial heap update for the source vertex
    Q.heapUpdate(V[s][0], s);

    // Relax function
    _ relax = [](_ & V, _ u, _ v, _ w) {
        if (V[v][0] > V[u][0] + w) {
            V[v][0] = V[u][0] + w; // update the distance
            V[v][1] = u;           // update the parent
            return true;            // return true if relaxed
        }
        return false;
    };

    while (len(Q) > 0) {
        _ u = (--Q)[1];  // vertex id with minimum distance is popped
        
        // for every neighbor v and weight w of u, call relax
        G1[u] | $(v, w) { 
            if (relax(V, u, v, w)) {
                Q.heapUpdate(V[v][0], v); // update priority queue only if relaxed
            }
            yield;
        };
    }

    // Print results
    for (_[i, x] : V) {
        print("Shortest distance to vertex ", i, " is ", x[0], " units via vertex ", x[1]);
    }

    return 0;
}
