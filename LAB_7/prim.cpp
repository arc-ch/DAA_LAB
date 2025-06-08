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

    _ seq = range(len(G1)), V = seq | $(i) {   //"For each i in seq, apply the function that returns {inf, -1}."
            return {inf, -1};                   // Initialize Vertex array
        };

    _ Q = heap(seq | $(i){ return {inf, i}; }); // priority Q[priority,index]

    let s = 0; //set the source vertex

    V[s][0] = 0;  //set the distance component of the source vector as 0

    // So for now only this has distance 0 all others have infinity 

    Q.heapUpdate(V[s][0], s); //Update pq with starting vertex

    while (len(Q) > 0)
    {
        // we need only vertex id
            _ u = (--Q)[1];  // only vertec id is popped ,[0] for priority
            print(V[u][1], u, "weight = ", V[u][0]);

            G1[u] | $(v, w)  //For each (v, w) in the adjacency list of u, do below stuffs
            {   
                if(w < V[v][0])
                    {
                        V[v][1] = u; //update parent

                        V[v][0] = w; //update distance
                        Q.heapUpdate(V[v][0], v); // Update Priority Queue upon changes in relax func
                    }
                yield; // or return NULL
            };

            //print(u);
    }

    // for ( _[i, x]: V)
    // print(" Shortest distasnce to vertex ", i, "is", x[0]," units via vertex",x[1]);
    
    //print(seq);
    //print(V);
    return 0;
}
