#include "cmm.H"
int main(){
    //Dynamic Proghramming
    //0/1 KNAPSACK

    range(10) | $(i) {
        print(i, " : "$$(
            $(n) { return {n < 2, 1}; },
            $(n) { return {n-1, n-2}; },
            $(a, b, n) { return a+b; },
            i
        ));
        yield
    };
    return 0;
}

