#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        string s;
        cin >> s;
        map<char, int> count;
        for (int j = 0; j < s.length(); j++) {
            count[s[j]]++;
        }
        int count_ge_two = 0;
        int count_one = 0;
        for (char c = 'a'; c <= 'z'; c++) {
            if (count[c] == 1) {
                count_one++;
            }
            else if (count[c] >= 2) {
                count_ge_two++;
            }
        }
        cout << count_ge_two + count_one/2 << endl;
    }
}