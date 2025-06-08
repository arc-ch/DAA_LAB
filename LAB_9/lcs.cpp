#include "cmm.H"
int main() {
        int count = 0;
    _ l1 = get(range(3), get(range(5, 10)));
    _ l2 = get(range(3), get(range(5, 10)));
        print("l1: ", l1);
        print("l2: ", l2);
    _ result = $$(
        $(i, j) { return {i == -1 || j == -1, {0, null}}; }, // if i and j = 0 then return 0 and null means lcs is empty (sequence) as our operation will work from i,j = 1
        $(i, j) { return {
            /* Diagonal */ {i - 1, j - 1},
            {/* North */ i - 1, j},
            {/* West */ i, j - 1}
        }; },
        $(D, N, W, i, j) {
            // add counter here => count++
            count ++;
            if (l1[i] == l2[j]) {  // add braces and parentheses
                return {D[0] + 1, D[1] + l1[i]};  // length and lcs returned   // RULE 1
            }
            return (N[0] < W[0]) ? W : N;    // WHEN NORTH IS GREATER, NORTH IS RETURNED, ELSE WEST IS RETURNED // RULE 2
        }, 
        {len(l1) - 1, len(l2) - 1}
    );

    print("LCS: ", result);
    print("Steps: ", count);

    return 0;
}

//add counter and steps taken in lab copy in that format 