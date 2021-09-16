#include <iostream>
#include <string>

using namespace std;

int move(string& Gregor, string& enemy, int i, int n) {
    if (enemy[i] == '0') {
        if (Gregor[i] == '1') {
            enemy[i] = '1';
            Gregor[i] = '0';
            return 1;
        }
        else {
            return 0;
        }
    }
    else {
        if (i > 0 && Gregor[i-1] == '1') {
            Gregor[i-1] = '0';
            return 1;
        }
        else if (i < n-1 && Gregor[i+1] == '1') {
            Gregor[i+1] = '0';
            return 1;
        }
        else {
            return 0;
        }
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        string enemy;
        cin >> enemy;
        string Gregor;
        cin >> Gregor;
        int count = 0;
        for (int i = 0; i < n; i++) {
            count += move(Gregor, enemy, i, n);
        }
        cout << count << endl;
    }
}