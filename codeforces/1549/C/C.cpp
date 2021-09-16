#include <iostream>
#include <vector>

using namespace std;

void add_friendship(vector<int>& friendships, int u, int v, int& vulnerable) {
    if (v > u) {
        friendships[u]++;
        if (friendships[u] == 1) {
            vulnerable++;
        }
    }
    else {
        friendships[v]++;
        if (friendships[v] == 1) {
            vulnerable++;
        }
    }
}

void remove_friendship(vector<int>& friendships, int u, int v, int& vulnerable) {
    if (v > u) {
        friendships[u]--;
        if (friendships[u] == 0) {
            vulnerable--;
        }
    }
    else {
        friendships[v]--;
        if (friendships[v] == 0) {
            vulnerable--;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> friendships (n+1);
    int vulnerable = 0;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        add_friendship(friendships, u, v, vulnerable);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            add_friendship(friendships, u, v, vulnerable);
        }
        else if (type == 2) {
            int u, v;
            cin >> u >> v;
            remove_friendship(friendships, u, v, vulnerable);
        }
        else {
            cout << n - vulnerable << endl;
        }
    }
}