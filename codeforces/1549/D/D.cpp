#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long gcd(long long a, long long b) {
    // Euclid's algorithm
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

vector<vector<long long>> gcd_sparse_table (vector<long long>& d) {
    int N = d.size();
    int K = ceil(log2(N));
    vector<vector<long long>> sparse_table (N, vector<long long> (K+1));
    for (int i = 0; i < N; i++) {
        sparse_table[i][0] = d[i];
    }
    for (int j = 1; j <= K; j++) {
        for (int i = 0; i + (1 << j) <= N; i++) {
            sparse_table[i][j] = gcd(sparse_table[i][j-1], sparse_table[i + (1 << (j-1))][j-1]);
        }
    }
    return sparse_table;
}

long long range_gcd(vector<vector<long long>>& sparse_table, int i, int j) {
    // returns gcd [d_i, ..., d_j]
    int k = floor(log2(j - i + 1));
    return gcd(sparse_table[i][k], sparse_table[j - (1 << k) + 1][k]);
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<long long> a (n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        if (n == 1) {
            cout << 1 << endl;
            continue;
        }
        vector <long long> d (n-1);
        for (int i = 0; i < n-1; i++) {
            d[i] = a[i+1] - a[i];
        }
        vector<vector<long long>> sparse_table = gcd_sparse_table(d);
        int largest_friend_group = 1;
        int l = 0;
        int r = 0;
        while (r < n-1) {
            if (abs(range_gcd(sparse_table, l, r)) != 1) {
                largest_friend_group = max(largest_friend_group, r - l + 2);
            }
            else {
                l++;
            }
            r++;
        }
        cout << largest_friend_group << endl;
    }
}

/*
int largest_friend_group(vector<long long>& d, int m) {
    bool found_nonzero = false;
    for (int i = 0; i < m-1; i++) {
        d[i] = gcd(d[i], d[i+1]);
        if (d[i] > 1) {
            found_nonzero = true;
        }
    }
    if (found_nonzero) {
        return 1 + largest_friend_group(d, m-1);
    }
    else {
        return 1;
    }
}
*/