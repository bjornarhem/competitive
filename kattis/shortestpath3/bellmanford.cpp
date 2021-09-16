// https://open.kattis.com/problems/shortestpath3

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
while(true) {
    int n, m, q, s;
    cin >> n >> m >> q >> s;
    if (n == 0) { return 0; }

    vector<vector<int>> edges;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    int INF = 1000000000;
    vector<int> dist (n, INF);
    dist[s] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            vector<int> edge = edges[j];
            int origin = edge[0];
            int destination = edge[1];
            int weight = edge[2];
            if (dist[origin] != INF) {
                dist[destination] = min(weight + dist[origin], dist[destination]);
            }
        }
    }

    bool new_negative_cycle_path = true;
    while (new_negative_cycle_path) {
        new_negative_cycle_path = false;
        for (int j = 0; j < m; j++) {
            vector<int> edge = edges[j];
            int origin = edge[0];
            int destination = edge[1];
            int weight = edge[2];
            if (dist[destination] > weight + dist[origin]) {
                if (dist[destination] != -INF && dist[origin] != INF) {
                    new_negative_cycle_path = true;
                    dist[destination] = -INF;
                }
            }
        }
    }

    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        if (dist[x] == INF) {
            cout << "Impossible" << endl;
        }
        else if (dist[x] == -INF) {
            cout << "-Infinity" << endl;
        }
        else {
            cout << dist[x] << endl;
        }
    }
    cout << endl;
}
}
