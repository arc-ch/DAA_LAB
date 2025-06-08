#include "cmm.H"
int main(){
    // Dynamic Proghramming
    // 0/1 KNAPSACK

    // range(10) | $(i) {
    //     print(i, " : ", $$(
    //         $(n) { return {n < 2, n}; },    // base case  if less than 2 return n 
    //         $(n) { return {n-1, n-2}; },    // divide   
    //         $(a, b, n) { return a+b; },     // conquer
    //         i
    //     ));
    //     yield;
    // };

    let n = 5, count = 0;
    _ w = get(range(1,20), n),
      v = get(range(1,100), n),
      W = 5*n;
      
      print(n,"items");
      print(w,"weight");
      print(v,"values");
      print(W,"Capacity");

    
    _ result = $$(
        $(i, j) { return {i < 0 || j<=0, {0 , null}}; },
        $(i, j) { return {{i - 1 , j}, {i-1 , j - w[i]}}; }, //1 unit N and 1 unit N & West
        $(v1, v2, i, j){
                ++count;
                // if(count % 100 == 0) print(count);
                if(w[i] > j) return v1; // only north value returned
                if (v2[0] +v[i]> v1[0]) 
                    return {v2[0] +v[i], v2[1] + i}; // if included add the north + west value 
                return v1; // only north value returned
        },
        {n-1, W}
    );
    print(result);
    print(count,"steps");
    
    _ randomArray = null;
    srandom(time(0));
    for (let i = 0; i < 100; ++i){
        randomArray += random() % 100;
    }
    print(randomArray);
    return 0;
}


