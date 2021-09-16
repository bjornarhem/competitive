#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long good_subarrays(int n, vector<long long> a) {
    long long num_good = 2*n - 1; //accounting for length 1 and 2 subarrays

    // Count good length 3 subarrays
    for (int i = 0; i < n - 2; i++) {
        if (a[i+1] < min(a[i], a[i+2]) || a[i+1] > max(a[i], a[i+2])) {
            num_good++;
        }
    }

    // Count good length 4 subarrays
    for (int i = 0; i < n - 3; i++) {
        if (
            min(a[i+1], a[i+2]) < min(a[i], a[i+3])
            && max(a[i], a[i+3]) < max(a[i+1], a[i+2])
        ) {
            num_good++;
        }
    }

    return num_good;
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
        cout << good_subarrays(n, a) << endl;
    }
}