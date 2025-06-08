#include"cmm.H"

int main(){

     let arr = {{4,"a"},{1,"b"},{5,"c"},{1,"d"},{1,"e"}};
    // let q = heap({{4,"a"},{1,"b"},{5,"c"},{1,"d"},{1,"e"}});
    // let q =  heap({{10,"a"},{25,"b"},{15,"c"},{30,"d"},{20,"e"}});
     let q = heap({{5,"g"},{9,"a"},{12,"t"},{16,"c"},{13,"e"},{45,"s"}});

    //removing 1,"e" and add them separately 
    // let arr = {{4,"a"},{1,"b"},{5,"c"},{1,"d"}};
    // let q = heap({{4,"a"},{1,"b"},{5,"c"},{1,"d"}});

    // arr<<= {1,"e"}; //adding another element separately later on
    // q <<= {1,"e"};
    // q.heapUpdate(100,"b");
     print("Content of array: ");

    while(len(arr) > 0) 
        print(--arr);

    print("Content of Priority Queue: ");
    while(len(q) > 0) 
        print(--q);

    //return 0;
    // HUFFMAN CODE IMPLEMENTATION
   // let hm = heap({{4,"a"},{1,"b"},{5,"c"},{1,"d"},{1,"e"}});
   // let hm = heap({{10,"a"},{25,"b"},{15,"c"},{30,"d"},{20,"e"}});
    let hm = heap({{5,"g"},{9,"a"},{12,"t"},{16,"c"},{13,"e"},{45,"s"}});
   // let _min1, _min2; // to hold smallest elements for merging

    print("Generated Huffman Codes:");
    while(len(hm) > 1) 
    { // while more than 1 get min1 and min2 and merge them 
        _ min1 = --hm;  // smallest elemetn
        _ min2 = --hm;  // 2nd smallest element

        hm <<= {min1[0] + min2[0], {min1[1], min2[1]}};
        //print(hm);
    }

    let hmStr = $(t, s) {
        if(t.isstr()) return t + "=" + s + " ";
        return hmStr(t[0], s+"0") + hmStr(t[1], s+"1");
    };
    _ ans = --hm;

    
    print(hmStr(ans[1], ""));
    return 0;
}


// IN LAB FILE WRITE PSEUDOCODE AND EXPLAIN HOW TO CONVERT TREE(Z) USED IN PQ  
// write tree to string conversion
// 2 sample ip/ op
