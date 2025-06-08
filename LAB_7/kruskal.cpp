// #include "cmm.H"

// // Disjoint Set (Union-Find) Functions
// _ find(_ parent, _ i) {
//     if (parent[i] == i) return i;
//     return parent[i] = find(parent, parent[i]); // Path compression
// }

// void unionSet(_ parent, _ level, _ x, _ y) {
//     _ rootX = find(parent, x);
//     _ rootY = find(parent, y);

//     if (level[rootX] < level[rootY]) {
//         parent[rootX] = rootY;
//     } else if (level[rootX] > level[rootY]) {
//         parent[rootY] = rootX;
//     } else {
//         parent[rootY] = rootX;
//         level[rootX]++;
//     }
// }

// int main() {
//     // Graph G1 represented as an adjacency list (vertex -> (neighbor, weight))
//     let G1 = {
//         /*0*/ {{1,4},{7,8}},   
//         /*1*/ {{0,4}, {2,8}, {7,11}},
//         /*2*/ {{1,8},{8,2},{5,4},{3,7}},
//         /*3*/ {{2,7},{4,9},{5,14}},
//         /*4*/ {{3,9},{5,10}},
//         /*5*/ {{2,4},{3,14},{4,10},{6,2}},
//         /*6*/ {{5,2},{7,1},{8,6}},
//         /*7*/ {{0,8},{1,11},{6,1},{8,7}},
//         /*8*/ {{2,2},{6,6},{7,7}}
//     };

//     let numVertices = len(G1);

//     // Convert adjacency list to edge list
//     _ edges = {};
//     G1 | $(u, neighbors) {
//         neighbors | $(v, w) {
//             edges.push_back({u, v, w});  // Add edge u -> v with weight w
//         };
//     };

//     // Sort edges by their weights 
//     edges = edges | sortedBy([](_ e1, _ e2){ return e1[2] < e2[2]; });

//     // Initialize Union-Find structures
//     _ parent = seq(numVertices) | $(i){ return i; };  // Parent array for Union-Find
//     _ level = vector(numVertices, 0);  // Level array for Union-Find

//     _ MST = {};  // To store the resulting Minimum Spanning Tree

//     print("Starting Kruskal's Algorithm...\n");

//     for (_[u, v, w]: edges) {
//         _ rootU = find(parent, u);
//         _ rootV = find(parent, v);

//         // If u and v belong to different components, add this edge to the MST
//         if (rootU != rootV) {
//             MST.push_back({u, v, w});
//             unionSet(parent, level, rootU, rootV);  // Union the two components

//            // print("Added edge (", u, " to ", v, "), weight = ", w);
//         }
//     }

//     // Print the final Minimum Spanning Tree (MST) summary
//     print("\nFinal Minimum Spanning Tree (MST):");
//     for (_[u, v, w]: MST) {
//         print("Edge (", u, " to ", v, "), weight = ", w);
//     }

//     return 0;
// }
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

// Disjoint Set (Union-Find) Functions without using level
int find(vector<int>& parent, int i) {
    if (parent[i] == i) return i;
    return parent[i] = find(parent, parent[i]); // Path compression
}

void unionSet(vector<int>& parent, int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);

    // Attach rootY under rootX arbitrarily
    if (rootX != rootY) {
        parent[rootY] = rootX;
    }
}

int main() {
    // Graph G1 represented as an adjacency list (vertex -> (neighbor, weight))
    vector<vector<pair<int, int>>> G1 = {
        /*0*/ {{1,4},{7,8}},   
        /*1*/ {{0,4}, {2,8}, {7,11}},
        /*2*/ {{1,8},{8,2},{5,4},{3,7}},
        /*3*/ {{2,7},{4,9},{5,14}},
        /*4*/ {{3,9},{5,10}},
        /*5*/ {{2,4},{3,14},{4,10},{6,2}},
        /*6*/ {{5,2},{7,1},{8,6}},
        /*7*/ {{0,8},{1,11},{6,1},{8,7}},
        /*8*/ {{2,2},{6,6},{7,7}}
    };

    int numVertices = G1.size();

    // Convert adjacency list to edge list
    vector<tuple<int, int, int>> edges;
    for (int u = 0; u < numVertices; ++u) {
        for (auto [v, w] : G1[u]) {
            edges.push_back({u, v, w});  // Add edge u -> v with weight w
        }
    }

    // Sort edges by their weights for Kruskal's Algorithm
    sort(edges.begin(), edges.end(), [](auto& e1, auto& e2) {
        return get<2>(e1) < get<2>(e2); // Compare by weight (third element of edge)
    });

    // Initialize Union-Find structures
    vector<int> parent(numVertices);
    for (int i = 0; i < numVertices; ++i) parent[i] = i;

    vector<tuple<int, int, int>> MST;  // To store the resulting Minimum Spanning Tree

    for (auto [u, v, w] : edges) {
        int rootU = find(parent, u);
        int rootV = find(parent, v);

        // If u and v belong to different components, add this edge to the MST
        if (rootU != rootV) {
            MST.push_back({u, v, w});
            unionSet(parent, u, v);  // Union the two components
        }
    }

    // Print the final Minimum Spanning Tree (MST) summary
    cout << "\nFinal Minimum Spanning Tree (MST):" << endl;
    for (auto [u, v, w] : MST) {
        cout << "Edge (" << u << " to " << v << "), weight = " << w << endl;
    }

    return 0;
}
