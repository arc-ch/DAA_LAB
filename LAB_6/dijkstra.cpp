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

    _ seq = range(len(G1)), V = seq | $(i) {   //"For each i in seq, apply the function that returns {inf, -1}."
            return {inf, -1};
        };

    _ Q = heap(seq | $(i){return {inf, i}; }); // priority q

    let s = 0; //set the source vertex

    V[s][0] = 0;  //set the distance component of the source vector as 0

    // So for now only this has distance 0 all others have infinity 

    Q.heapUpdate(V[s][0], s);

    //RELAX FUNCTION
    _ relax = [](_ & V, _ u, _ v, _ w){
        
        if (V[v][0] > V[u][0] + w) //// u.d = V[v][0] // all distances are stored in V so we go to V[u][0]
        {
            V[v][0] = V[u][0] + w; // update the distandce
            V[v][1] = u;           // Update the parent 
            //Q.heapUpdate(V[v][0], v); // Update Priority Queue upon changes 
        }
    };

    while (len(Q) > 0)
    {
        // we need only vertex id
            _ u = (--Q)[1];  // only vertec id is popped 
            
            //for every v and w call relax func
            G1[u] | $(v, w)  //For each (v, w) in the adjacency list of u, do below stuffs
            { 
                relax(V, u, v, w);
                Q.heapUpdate(V[v][0], v); // Update Priority Queue upon changes in relax func
                yield; // or return NULL
            };

            //print(u);
    }

    for ( _[i, x]: V)
    print(" Shortest distasnce to vertex ", i, "is", x[0]," units via vertex",x[1]);

    let a = {10, 20}, b = {30, 40};
    print(a<<=b);
    //print(seq);
    //print(V);
    return 0;
}
