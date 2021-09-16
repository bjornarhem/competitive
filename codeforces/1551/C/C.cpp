#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int num_occurences(char c, string word) {
    int occurences = 0;
    int length = word.length();
    for (int i = 0; i < length; i++) {
        if (word[i] == c) {
            occurences++;
        }
    }
    return occurences;
}

int char_balance(char c, string word) {
    return 2*num_occurences(c, word) - word.length();
}

struct Local {
    Local(char paramA) { this->paramA = paramA; }
    bool operator () (string i, string j) {
        return char_balance(this->paramA, i) > char_balance(this->paramA, j);
    }

    char paramA;
};

int get_max_words(char c, vector<string> &words) {
    // sort words by occurences of character
    sort(words.begin(), words.end(), Local(c));

    int num_words = 0;
    long long c_balance = 0;
    int length = words.size();
    for (int i = 0; i < length; i++) {
        c_balance = c_balance + 2*num_occurences(c, words[i]) - words[i].length();
        if (c_balance > 0) {
            num_words++;
        }
        else {
            break;
        }
    }
    return num_words;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<string> words (n);
        for (int j = 0; j < n; j++) {
            cin >> words[j];
        }
        int max_words = 0;
        for (char c = 'a'; c <= 'e'; c++) {
            max_words = max(max_words, get_max_words(c, words));
        }
        cout << max_words << endl;
    }
}