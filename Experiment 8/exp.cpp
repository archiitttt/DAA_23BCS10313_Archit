#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

typedef pair<int, int> pii; 
// first = distance, second = vertex

void dijkstra(int start, vector<vector<pii>> &graph) {
    int n = graph.size();

    vector<int> dist(n, numeric_limits<int>::max());
    dist[start] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        // Ignore outdated entries
        if (d > dist[u]) continue;

        // Relax edges
        for (auto &edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    // Print results
    cout << "Shortest distances from vertex " << start << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "To " << i << " = " << dist[i] << endl;
    }
}

int main() {
    int n, e;
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    vector<vector<pii>> graph(n);

    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});  // remove for directed graph
    }

    int start;
    cout << "Enter start vertex: ";
    cin >> start;

    dijkstra(start, graph);

    return 0;
}
