#include <iostream>
#include <vector>
#include <set>

using namespace std;

void dfs(vector<vector<int>>& edge, int node, set<int>& seen) {
    for (int i = 0; i < edge[node].size(); i++) {
        if (seen.find(edge[node][i]) == seen.end()) {
            seen.insert(edge[node][i]);
            dfs(edge, edge[node][i], seen);
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> edge (n);
    for (int i = 0; i < n; i++) {
        int num_edges;
        cin >> num_edges;
        for (int j = 0; j < num_edges; j++) {
            int non_imposter;
            cin >> non_imposter;
            edge[non_imposter-1].push_back(i);
        }
    }

    for (int i = 0; i < n; i++) {
        set<int> seen = {i};
        dfs(edge, i, seen);
        int supporters = seen.size();
        cout << (supporters > k) << endl;
    }
}