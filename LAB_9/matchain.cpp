#include "cmm.H"
int main (){

    _ mat = get(range(1,10), get(range(5,8)));
    print(mat);

    _ result = $$(
        $(i, j) { return{ i == j, {0,null}};},
        $(i, j) {
            _ a = null;
            // Enumerate "a" wih all locations of previous solutions corresponding to various fessible cutting points
            for( _ k = i; k < j; ++k) a+={{i, k}, {k+1, j}}; // i to k with k + 1
            return a;            //index=    0        1
            
        },
        $(m, i, j){
            _ v = inf, s = null;

            for(_ k = i; k < j; ++k){
                _ q = m[2*(k-1)][0] + mat[i] * mat[k] * mat[j] + m[2*(k-1)+1][0];

                //_ q = m[2*k][0] + mat[i]* mat[i+1+k]* mat[j] + m[2*k+1][0]; //at 0th idx we have the ans see line 12
                //change above line from amitnashu photo taken 

            
                if(q < v){
                    v = q;
                    s = m[2*k - 1][1] + k + m[2*(k-i)+1][1];
                }
        }
            // m contains the solutions at all
            // relevant previous locations of cutting points 
            //update v with the minimum cost option 
            // update s with the split location( cutting point) corresponsing
            // to the minimum cost solution
            return{v,s}; // v is the cost and s is the sub sequence of cutting points
        },
        {0, len(mat) - 2}

    );

    print("matrix chain: ", result);
    return 0;
}
