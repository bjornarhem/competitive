// https://open.kattis.com/problems/base2palindrome

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <bitset>

using namespace std;

string binConverter(int number) {
	string bin;
	char holder = ' ';
	while (number != 0)
	{
		holder = number % 2 + '0';
		bin = holder + bin;
		number /= 2;
	}
	return bin;
}

int main(void) {
	int M;
	while (cin >> M) {
		string output;
		int n = floor(log2(M+1));
		int digits;
		int a = exp2(n) - 1;
		int b = exp2(n) + exp2(n - 1) - 1;
		int first_n_digits;
		if (M >= b) {
			digits = 2 * n;
			first_n_digits = exp2(n - 1) + M - b;
			string leftSide = binConverter(first_n_digits);
			output = leftSide;
			for (int i = 0; i < n; i++) {
				char character = leftSide[n - 1 - i];
				if (character == '1') {
					output.append("1");
				}
				else {
					output.append("0");
				}
			}
		}
		else {
			digits = 2 * n - 1;
			first_n_digits = exp2(n - 1) + M - a;
			string leftSide = binConverter(first_n_digits);
			output = leftSide;
			for (int i = 1; i < n; i++) {
				char character = leftSide[n - 1 - i];
				if (character == '1') {
					output.append("1");
				}
				else {
					output.append("0");
				}
			}
		}
		cout << stoi(output, nullptr, 2) << endl;
	}
	return 0;
}
