#include <iostream>

using namespace std;

bool possible(int n, int m, int k) {
    if (n%2 == 0 && m%2 == 0) {
        return k%2 == 0;
    }
    else if (n%2 == 0 && m%2 == 1) {
        return (k <= (n/2)*(m-1)) && (k % 2 == 0);
    }
    else if (n%2 == 1) {
        return (k >= m/2) && (k % 2 == (m/2) % 2);
    }
}

void output_solution(int n, int m, int k) {
    if (n%2 == 0 && m%2 == 0) {
        return k%2 == 0;
    }
    else if (n%2 == 0 && m%2 == 1) {
        return (k <= (n/2)*(m-1)) && (k % 2 == 0);
    }
    else if (n%2 == 1) {
        return (k >= m/2) && (k % 2 == (m/2) % 2);
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, m, k;
        cin >> n >> m >> k;
        if (possible(n, m, k)) {
            cout << "YES" << endl;
            output_solution(n, m, k);
        }
        else {
            cout << "NO" << endl;
        }
    }
}