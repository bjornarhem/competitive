#include <iostream>
#include <string>

using namespace std;

int g(int n, string s) {
    char prev = s[0];
    int blocks = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] != prev) {
            prev = s[i];
            blocks++;
        }
    }
    return blocks;
}

int f(int n, int a, int b, string s) {
    if (b >= 0) {
        return (a+b)*n;
    }
    else {
        return a*n + b*(g(n, s)/2 + 1);
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, a, b;
        cin >> n >> a >> b;
        string s;
        cin >> s;
        cout << f(n, a, b, s) << endl;
    }
}