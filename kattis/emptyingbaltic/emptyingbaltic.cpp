#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<int> altitude (h*w);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> altitude[i*w + j];
        }
    }
    int drain_i, drain_j;
    cin >> drain_i >> drain_j;
    vector<vector<int>> edges (h*w);
    for (int i = 0; i < h*w; i++) {
        if (i%w) {
            edges[i-1].push_back(i);
            edges[i].push_back(i-1);
        }
        if (i >= w) {
            edges[i-w].push_back(i);
            edges[i].push_back(i-w);
        }
        if (i%w && i >= w) {
            edges[i].push_back(i-w-1);
            edges[i-w-1].push_back(i);
        }
        if (i%w && i < w*(h-1)) {
            edges[i].push_back(i+w-1);
            edges[i+w-1].push_back(i);
        }
    }
    // Do Prim's algorithm on edges with max(altitude_i, altitude_j) as edge weight, and max in stead of sum
    priority_queue<pair<int, int>> pq;
    int drain = (drain_j-1) + w*(drain_i-1);
    for (int i = 0; i < edges[drain].size(); i++) {
        int weight = min(-altitude[drain], -altitude[edges[drain][i]]);
        pq.push(make_pair(weight, edges[drain][i]));
    }
    set<int> visited_nodes = {drain};
    long long drained_water = -altitude[drain];

    while (!pq.empty()) {
        pair<int, int> next = pq.top();
        pq.pop();
        if (visited_nodes.find(next.second) == visited_nodes.end() && next.first > 0) {
            visited_nodes.insert(next.second);
            drained_water += next.first;
            for (int i = 0; i < edges[next.second].size(); i++) {
                int weight = min(next.first, -altitude[edges[next.second][i]]);
                pq.push(make_pair(weight, edges[next.second][i]));
            }
        }
    }

    std::cout << drained_water << endl;
    return 0;
}