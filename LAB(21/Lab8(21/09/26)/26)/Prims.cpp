#include <bits/stdc++.h>
using namespace std;

int prims(int V, vector<vector<pair<int, int>>> &adj) {

    // {weight, node}
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    vector<int> visited(V, 0);

    // Start from node 0
    pq.push({0, 0});

    int mstCost = 0;
    int count = 0;

    while (!pq.empty()) {

        // Get minimum weight edge
        pair<int, int> current = pq.top();
        pq.pop();

        int weight = current.first;
        int node = current.second;

        // If already visited, skip
        if (visited[node] == 1) {
            continue;
        }

        // Include node in MST
        visited[node] = 1;
        mstCost += weight;
        count++;

        // Add all adjacent edges
        for (auto edge : adj[node]) {

            int neighbor = edge.first;
            int edgeWeight = edge.second;

            if (visited[neighbor] == 0) {
                pq.push({edgeWeight, neighbor});
            }
        }
    }

    // Graph is disconnected
    if (count != V) {
        return -1;
    }

    return mstCost;
}

int main() {

    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<pair<int, int>>> adj(V);

    cout << "Enter edges (u v weight):" << endl;

    for (int i = 0; i < E; i++) {

        int u, v, weight;
        cin >> u >> v >> weight;

        // Undirected graph
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }

    int ans = prims(V, adj);

    if (ans == -1) {
        cout << "MST does not exist. Graph is disconnected." << endl;
    }
    else {
        cout << "Minimum Cost of MST = " << ans << endl;
    }

    return 0;
} 