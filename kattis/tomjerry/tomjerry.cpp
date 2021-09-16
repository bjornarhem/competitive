#include <iostream>
#include <vector>
#include <utility>
#include <set>

using namespace std;

const long long big_divisor = 1000000007;

bool has_cheese(int x, int y, set<pair<int, int>> set) {
    return set.find(make_pair(x, y)) != set.end();
}

int main() {
    int w, h;
    cin >> w >> h;
    int n;
    cin >> n;
    set<pair<int, int>> cheese;
    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        cheese.insert(make_pair(x-1, y-1));
    }
    vector<long long> num_paths_cur (h+1);
    vector<long long> num_paths_prev (h+1);
    vector<long long> num_cheese_paths_cur (h+1);
    vector<long long> num_cheese_paths_prev (h+1);
    for (int i = w-1; i >= 0; i--) {
        for (int j = h-1; j >= 0; j--) {
            if (i == w-1 && j == h-1) {
                num_paths_cur[j] = 1;
                num_cheese_paths_cur[j] = has_cheese(i, j, cheese);
            }
            else{
                num_paths_cur[j] = (num_paths_prev[j] + num_paths_cur[j+1]) % big_divisor;
                if (has_cheese(i, j, cheese)) {
                    num_cheese_paths_cur[j] = num_paths_cur[j];
                }
                else {
                    num_cheese_paths_cur[j] = (num_cheese_paths_prev[j] + num_cheese_paths_cur[j+1]) % big_divisor;
                }
            }
        }
        num_paths_prev = num_paths_cur;
        num_cheese_paths_prev = num_cheese_paths_cur;
    }

    cout << num_cheese_paths_cur[0] << endl;
}