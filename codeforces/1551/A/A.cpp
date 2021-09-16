#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        long long n;
        cin >> n;
        long long k = n / 3;
        if (n % 3 == 0) {
            cout << k << " " << k << endl;
        }
        else if (n % 3 == 1) {
            cout << k+1 << " " << k << endl;
        }
        else if (n % 3 == 2) {
            cout << k << " " << k+1 << endl;
        }
    }
}