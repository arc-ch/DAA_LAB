#include "cmm.H"

int main() {
    // Assume mygraph is defined as a graph with edges (u, v, weight)
    _ mygraph = {
        {0, 1, 4}, {0, 7, 8}, {1, 2, 8}, {1, 7, 11},
        {2, 3, 7}, {2, 5, 4}, {2, 8, 2}, {3, 4, 9},
        {4, 5, 10}, {5, 6, 2}, {6, 7, 1}, {6, 8, 6}, 
        {7, 8, 7}
    };

    // Sorting edges by weight using a lambda function
    mygraph.sort([](_ edge1, _ edge2) { return edge1[2] < edge2[2]; });

    // Union-Find data structures
    _ parent = range(len(mygraph)) | $(i) { return i; };
    _ rank = range(len(mygraph)) | $(i) { return 0; };

    // Function to find the root of a set
    auto find = [&parent](int i) {
        if (parent[i] != i) {
            parent[i] = find(parent[i]);  // Path compression
        }
        return parent[i];
    };

    // Function to unite two sets
    auto unionSets = [&parent, &rank](int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    };

    // Kruskal's algorithm main logic
    _ MST = {};  // Minimum Spanning Tree to store the resulting edges

    for (const _& edge : mygraph) {
        int u = edge[0], v = edge[1], weight = edge[2];
        // If u and v are not connected, add the edge to the MST
        if (find(u) != find(v)) {
            unionSets(u, v);
            MST.push_back(edge);  // Add edge to MST
        }
    }

    // Print the resulting Minimum Spanning Tree edges
    cout << "Kruskal, minimum spanning-tree edges:\n";
    for (const _& edge : MST) {
        cout << "Edge (" << edge[0] << ", " << edge[1] << ") with weight " << edge[2] << "\n";
    }

    return 0;
}
