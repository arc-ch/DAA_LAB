#include<cmath>
#include"cmm.H"

int main(){
	let A = {1, 8, 8, 1, 9, 1, 3};
	_ partition = [] (_& A, _ p, _ r){
	   _ x = A[r]; // Pivot element
        _ i = p; // Index of smaller element
        for (_ j = p; j < r; ++j) {
            //++count;
            if (A[j] <= x) {
                std::swap(A[i], A[j]);
                ++i;
            }
        }
        std::swap(A[i], A[r]);
        return i;
    };

	
_ quicksort = [&] (_& A, _ p, _ r, _ f) ->void{
	if (p < r) 
	{
            _ q = partition(A, p, r);
            f(A, p, q - 1, f);
            f(A, q + 1, r, f);
	}
};

quicksort(A, 0, len(A) - 1, quicksort);
let data = {{10,2},{5,3},{15,5},{7,7},{3,1}};
print(A);
	print(data);
return 0;
}

