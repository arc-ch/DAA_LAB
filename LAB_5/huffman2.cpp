#include"cmm.H"

int main(){

     let arr = {{4,"a"},{1,"b"},{5,"c"},{1,"d"},{1,"e"}};
     let q = heap({{4,"a"},{1,"b"},{5,"c"},{1,"d"},{1,"e"}});

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
    let hm = heap({{4,"a"},{1,"b"},{5,"c"},{1,"d"},{1,"e"}});
   // let _min1, _min2; // to hold smallest elements for merging

    print("Generated Huffman Codes:");
    while(len(hm) > 1) { // while more than 1 get min1 and min2 and merge them 
    _ min1 = --hm;  // smallest elemetn
    _ min2 = --hm;  // 2nd smallest element

     hm <<= {min1[0] + min2[0], {min1[1], min2[1]}}; // putting the new value in heap=> add the frequencies (min1 + min2,"symbol of min1 , symbol of min2"
    //print(hm);
    }

    //return 0;
    let hmStr = $(t, s) {   // lambda func hmStr generates Huffman codes from the Huffman tree.

        if(t.isstr()) return t + "=" + s + " "; //t= node in huffman tree, s= string of huffcode generated so far
        return hmStr(t[0], s+"0") + hmStr(t[1], s+"1"); //appending 0 to left subtree and 1 to right subtree
    };

    _ ans = --hm;

    print(hmStr(ans[1], ""));
    return 0;
}


// IN LAB FILE WRITE PSEUDOCODE AND EXPLAIN HOW TO CONVERT TREE(Z) USED IN PQ  
// write tree to string conversion
// 2 sample ip/ op

/*
Let's walk through the code step by step with a detailed dry run, using the provided input to see how the Huffman coding process works.

### Initial Setup

- **Input:** An array of pairs where each pair contains a frequency and a character.
  - `arr = {{4,"a"}, {1,"b"}, {5,"c"}, {1,"d"}, {1,"e"}}`
- **Heap Initialization:**
  - The heap `q` is initialized with the same elements as `arr`.
  - The heap `hm` is also initialized with the same elements, which will be used to build the Huffman tree.

### Step 1: Printing the Initial Content

#### Printing `arr`:

- **Array `arr`:**
  - Initially: `{{4,"a"}, {1,"b"}, {5,"c"}, {1,"d"}, {1,"e"}}`
  - The program removes and prints elements one by one using `--arr` until `arr` is empty.
    - Iteration 1: `--arr` removes `{4,"a"}`, prints `4 a`
    - Iteration 2: `--arr` removes `{1,"b"}`, prints `1 b`
    - Iteration 3: `--arr` removes `{5,"c"}`, prints `5 c`
    - Iteration 4: `--arr` removes `{1,"d"}`, prints `1 d`
    - Iteration 5: `--arr` removes `{1,"e"}`, prints `1 e`
  - Final output: `4 a 1 b 5 c 1 d 1 e`

#### Printing `q` (Heap):

- **Heap `q`:**
  - Initially: Min-heap sorted by frequency, smallest first: `{{1,"b"}, {1,"d"}, {1,"e"}, {4,"a"}, {5,"c"}}`
  - The program removes and prints elements one by one using `--q` until `q` is empty.
    - Iteration 1: `--q` removes `{1,"b"}`, prints `1 b`
    - Iteration 2: `--q` removes `{1,"d"}`, prints `1 d`
    - Iteration 3: `--q` removes `{1,"e"}`, prints `1 e`
    - Iteration 4: `--q` removes `{4,"a"}`, prints `4 a`
    - Iteration 5: `--q` removes `{5,"c"}`, prints `5 c`
  - Final output: `1 b 1 d 1 e 4 a 5 c`

### Step 2: Building the Huffman Tree

#### Initial State of Heap `hm`:

- **Heap `hm`:**
  - Initially: Min-heap sorted by frequency, smallest first: `{{1,"b"}, {1,"d"}, {1,"e"}, {4,"a"}, {5,"c"}}`

#### Iteration 1:

- **Extract two smallest elements:**
  - `min1 = --hm;` removes `{1,"b"}`.
  - `min2 = --hm;` removes `{1,"d"}`.
- **Merge them and insert back:**
  - Create a new node: `{min1[0] + min2[0], {min1[1], min2[1]}} = {2, {"b","d"}}`.
  - Insert into heap: `hm <<= {2, {"b","d"}}`.
- **Heap after insertion:**
  - `hm = {{1,"e"}, {2, {"b","d"}}, {5,"c"}, {4,"a"}}`

#### Iteration 2:

- **Extract two smallest elements:**
  - `min1 = --hm;` removes `{1,"e"}`.
  - `min2 = --hm;` removes `{2, {"b","d"}}`.
- **Merge them and insert back:**
  - Create a new node: `{min1[0] + min2[0], {min1[1], min2[1]}} = {3, {"e", {"b","d"}}}`.
  - Insert into heap: `hm <<= {3, {"e", {"b","d"}}}`.
- **Heap after insertion:**
  - `hm = {{3, {"e", {"b","d"}}}, {5,"c"}, {4,"a"}}`

#### Iteration 3:

- **Extract two smallest elements:**
  - `min1 = --hm;` removes `{3, {"e", {"b","d"}}}`.
  - `min2 = --hm;` removes `{4,"a"}`.
- **Merge them and insert back:**
  - Create a new node: `{min1[0] + min2[0], {min1[1], min2[1]}} = {7, {{"e", {"b","d"}}, "a"}}`.
  - Insert into heap: `hm <<= {7, {{"e", {"b","d"}}, "a"}}`.
- **Heap after insertion:**
  - `hm = {{5,"c"}, {7, {{"e", {"b","d"}}, "a"}}}`

#### Iteration 4:

- **Extract two smallest elements:**
  - `min1 = --hm;` removes `{5,"c"}`.
  - `min2 = --hm;` removes `{7, {{"e", {"b","d"}}, "a"}}`.
- **Merge them and insert back:**
  - Create a new node: `{min1[0] + min2[0], {min1[1], min2[1]}} = {12, {"c", {{"e", {"b","d"}}, "a"}}}`.
  - Insert into heap: `hm <<= {12, {"c", {{"e", {"b","d"}}, "a"}}}`.
- **Heap after insertion:**
  - `hm = {{12, {"c", {{"e", {"b","d"}}, "a"}}}}`

### Final Huffman Tree Structure

At the end of the process, the heap `hm` contains a single element which is the root of the Huffman tree:

- **Tree Structure:**
  - Root: Frequency `12`, structure: `{"c", {{"e", {"b","d"}}, "a"}}`
  - Breaking it down:
    - `"c"` (left child): Huffman code `"0"`
    - Root’s right child: `{{"e", {"b","d"}}, "a"}` (right child): Huffman code `"1"`
      - `"a"` (right child): Huffman code `"11"`
      - The subtree `{"e", {"b","d"}}` (left child of the right subtree):
        - `"e"`: Huffman code `"100"`
        - The subtree `{"b","d"}` (right child):
          - `"b"`: Huffman code `"1010"`
          - `"d"`: Huffman code `"1011"`

### Step 3: Generating Huffman Codes

#### Lambda Function `hmStr`:

```cpp
let hmStr = $(t, s) {
    if(t.isstr()) return t + "=" + s + " ";
    return hmStr(t[0], s+"0") + hmStr(t[1], s+"1");
};
```

- **Call `hmStr(ans[1], "")` on the root of the tree:**
  - Initial call with `t = {"c", {{"e", {"b","d"}}, "a"}}` and `s = ""`.

#### Recursion Process:

1. **Root Node:**
   - `t = {"c", {{"e", {"b","d"}}, "a"}}`, `s = ""`
   - Left child: `hmStr("c", "0")`, returns `"c=0 "`.
   - Right child: `hmStr({{"e", {"b","d"}}, "a"}, "1")`.
  
2. **Right Subtree:**
   - `t = {{"e", {"b","d"}}, "a"}`, `s = "1"`
   - Left child: `hmStr({"e", {"b","d"}}, "10")`.
   - Right child: `hmStr("a", "11")`, returns `"a=11 "`.

3. **Left Subtree of Right Subtree:**
   - `t = {"e", {"b","d"}}`, `s = "10"`
   - Left child: `hmStr("e", "100")`, returns `"e=100 "`.
   - Right child: `hmStr({"b","d"}, "101")`.

4. **Leaf Nodes:**
   - `t = {"b","d"}`, `s = "101"`
   - Left child: `hmStr("b", "1010")`, returns `"b=1010 "`.
   - Right child: `hmStr("d", "1011")`, returns `"d=1011 "`.

#### Combining Results:
- The recursive calls return the following strings:
  - `"c=0 "`
  - `"e=100 "`
  - `"b=1010 "`
  - `"d=1011 "`
  - `"a=11 "`

- These are combined to form the final output: `c=0 e=100 b=1010 d=1011 a=11 `.

### Final Output

```cpp
print(hmStr(ans[1], ""));
```



- The program prints the Huffman codes for each character:
  - `c=0`
  - `e=100`
  - `b=1010`
  - `d=1011`
  - `a=11`

This string represents the Huffman codes for each character based on the frequencies provided. The result is optimized so that more frequent characters have shorter codes.
*/