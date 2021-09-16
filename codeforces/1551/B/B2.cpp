#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;
        vector<int> seq (n);
        vector<int> count (n+1);
        for (int j = 0; j < n; j++) {
            cin >> seq[j];
            count[seq[j]]++;
        }
        vector<queue<int>> color (n+1);
        int next_color = 1;
        int total_colored = 0;
        for (int j = 1; j < n+1; j++){
            total_colored += min(count[j], k);
        }
        total_colored = k * (total_colored / k);
        int colored = 0;
        for (int j = 1; j < n+1; j++){
            for (int h = 0; h < min(count[j], k); h++) {
                if (colored < total_colored) {
                    color[j].push(next_color);
                    next_color = (next_color % k) + 1;
                    colored++;
                }
            }
        }
        for (int j = 0; j < n; j++) {
            if (color[seq[j]].empty()) {
                cout << 0 << " ";
            }
            else {
                cout << color[seq[j]].front() << " ";
                color[seq[j]].pop();
            }
        }
        cout << endl;
    }
}