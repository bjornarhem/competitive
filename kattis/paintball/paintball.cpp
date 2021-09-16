#include <iostream>
#include <vector>

using namespace std;

bool bpm(vector<vector<int>>& edge_list, int u, vector<bool>& seen, vector<int>& matched) {
    if (edge_list[u].size() == 0) { return false; }

    for (int i = 0; i < edge_list[u].size(); i++) {
        int v = edge_list[u][i];
        if (!seen[v]) {
            seen[v] = true;
            if (matched[v] < 0) {
                matched[v] = u;
                return true;
            }
            else if (bpm(edge_list, matched[v], seen, matched)) {
                matched[v] = u;
                return true;
            }
        }
    }
    return false;
}

int main() {
    int N, M;
    cin >> N >> M;

    // vector<vector<bool>> bpGraph (N, vector<bool> (N, false));
    // for (int i = 0; i < M; i++) {
    //     int A, B;
    //     cin >> A >> B;
    //     bpGraph[A-1][B-1] = true;
    //     bpGraph[B-1][A-1] = true;
    // }

    vector<vector<int>> edge_list (N, vector<int> {});
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        edge_list[A-1].push_back(B-1);
        edge_list[B-1].push_back(A-1);
    }

    vector<int> matched (N, -1);
    for (int i = 0; i < N; i++) {
        vector<bool> seen (N, false);

        if (!bpm(edge_list, i, seen, matched)) {
            cout << "Impossible" << endl;
            return 0;
        }
    }

    for (int i = 0; i < N; i++) {
        cout << matched[i] + 1 << endl;
    }
}