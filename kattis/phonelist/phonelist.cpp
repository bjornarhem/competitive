// https://open.kattis.com/problems/phonelist

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main(){
	int t;
	while (cin >> t) {
		for (int h = 0; h < t; h++) {
			vector<vector<string>> numre = {};
			for (int i = 0; i < 11; i++) {
				vector<string> emptyvector = {};
				numre.push_back(emptyvector);
			}
			int n;
			cin >> n;
			map<string, bool> catalog;
			for (int i = 0; i < n; i++) {
				string p_str;
				cin >> p_str;
				int x = p_str.size();
				numre[x].push_back(p_str);
				catalog[p_str] = 1;
			}
			bool consistent = true;
			while (consistent){
				for (int i = 1; i < 11; i++) {
					int y = numre[i].size();
					for (int j = 0; j < y; j++) {
						for (int k = 1; k < i; k++) {
							string substring = numre[i][j].substr(0, k);
							if (catalog[substring] == 1) {
								consistent = false;
							}
						}
					}
				}
			break;
			}	
			if (consistent) { cout << "YES" << endl; }
			else { cout << "NO" << endl; }
		}
	}
    return 0;
}
