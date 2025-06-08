#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits>

using namespace std;

// Graph is represented as an adjacency list
vector<vector<pair<int, int>>> G1 = {
    /*0*/ {{1, 10}, {3, 5}},   // 0 connects to 1 with weight 10, 3 with weight 5
    /*1*/ {{2, 1}, {3, 2}},
    /*2*/ {{4, 4}},
    /*3*/ {{1, 3}, {2, 9}, {4, 2}},
    /*4*/ {{0, 7}, {2, 6}}
};

// Dijkstra's Algorithm
void dijkstra(int source, const vector<vector<pair<int, int>>>& graph) {
    int n = graph.size();  // Number of vertices
    vector<pair<int, int>> V(n, {numeric_limits<int>::max(), -1}); // Distance and parent
    V[source].first = 0; // Set distance to source vertex to 0

    // Priority queue: stores {distance, vertex}, sorted by distance
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    Q.push({0, source});

    // Relax function
    auto relax = [&](int u, int v, int w) {
        if (V[v].first > V[u].first + w) {  // If the new path is shorter
            V[v].first = V[u].first + w;    // Update the shortest distance
            V[v].second = u;                // Update the parent
            Q.push({V[v].first, v});        // Push updated distance to priority queue
        }
    };

    // Dijkstra's loop
    while (!Q.empty()) {
        int u = Q.top().second;  // Get the vertex with the smallest distance
        Q.pop();

        // Go through all neighbors of vertex u
        for (const auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int w = neighbor.second;
            relax(u, v, w); // Relax the edge (u -> v)
        }
    }

    // Print the shortest distances and paths
    for (int i = 0; i < n; ++i) {
        cout << "Shortest distance to vertex " << i << " is " << V[i].first
             << " units via vertex " << V[i].second << endl;
    }
}

int main() {
    int source = 0;  // Set the source vertex
    dijkstra(source, G1);  // Run Dijkstra's algorithm
    return 0;
}
