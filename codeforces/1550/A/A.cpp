#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int s;
        cin >> s;
        cout << ceil(sqrt(s)) << endl;
    }
}