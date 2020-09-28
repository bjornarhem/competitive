// https://open.kattis.com/problems/wordspin

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	string s_1, s_2;
	while(cin >> s_1 >> s_2){
		int string_length = s_1.length();
		vector<int> list (string_length + 2);
		for(int i = 1; i < string_length + 1; i++){
			int a = s_1[i-1];
			int b = s_2[i-1];
			list[i] = a-b;
		}
		list[0]=0;
		list[string_length+1]=0;
		int moves = 0;
		for(int j = 0; j < string_length + 1; j++){
			moves+=abs(list[j+1]-list[j]);
		}
		moves = moves/2;
		cout << moves << endl;

	}
}
