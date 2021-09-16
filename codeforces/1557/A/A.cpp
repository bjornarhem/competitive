#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

long long sum(vector<long long>& v) {
    long long s = 0;
    for (int i = 0; i < v.size(); i++) {
        s += v[i];
    }
    return s;
}

int main() {
    cout << setprecision(16);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<long long> a (n);
        for (int j = 0; j < n; j++) {
            cin >> a[j];
        }
        sort(a.begin(), a.end());
        double sum_1 = a[0];
        double sum_2 = sum(a) - a[0];
        double max_val = sum_1 + sum_2/(n-1);
        for (int k = 1; k < n-1; k++) {
            sum_1 += a[k];
            sum_2 -= a[k];
            max_val = max(max_val, sum_1/(k+1) + sum_2/(n - k - 1));
        }
        cout << max_val << endl;
    }
}