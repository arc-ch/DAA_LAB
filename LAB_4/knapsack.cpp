#include<cmath>
#include"cmm.H"
using namespace std;

int main(){
	let A = {1, 8, 8, 1, 9, 1, 3};
	_ partition = [] (_& A, _ p, _ r, _ cmp){
	   _ x = A[r]; // Pivot element
        _ i = p; // Index of smaller element
        for (_ j = p; j < r; ++j) {
            //++count;
            if (cmp(A[j],x)) {
                swap(A[i], A[j]);
                ++i;
            }
        }
        swap(A[i], A[r]);
        return i;
    };

	_ compareItems = [] (_ x, _ y){ return x[0]/x[1]<= y[0]/y[1];};

	_ quicksort = [&] (_& A, _ p, _ r, _ f) ->void{
		if (p < r) 
		{
				_ q = partition(A, p, r, compareItems);
				f(A, p, q - 1, f);
				f(A, q + 1, r, f);
		}
	};

quicksort(A, 0, len(A) - 1, quicksort);
let data = {{10,2},{5,3},{15,5},{7,7},{3,1}}; //{p,w} for knapsack
// for activity selection use stART AND FInish time
// sort acc to finish time


	_ greedyFractionalKnapsack =[&] (_& items, let w){
		let x = null;
		quicksort(items, 0, len(items) - 1, quicksort);
		_ remaining = w ;
		while(remaining > 0){
			_ best = items --; // post -- for pop operation
			_ qty = min(best[1], remaining);
			x <<= {best, qty};

			remaining = remaining - qty;
		}
		return x;

	};


print(greedyFractionalKnapsack(data, 10));
//print(A);
print(data);
return 0;
}
