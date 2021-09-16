// https://open.kattis.com/problems/generalchineseremainder

#include <iostream>
#include <cmath>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

long long inverse(long long a, long long m) {
	//return inverse of m1 modulo m2
	long long m0 = m, t, q;
	long long x0 = 0, x1 = 1;
	if (m == 1) {
		return 0;
	}
	while (a > 1) {
		q = a / m;
		t = m;
		m = a % m, a = t;
		t = x0;
		x0 = x1 - q * x0;
		x1 = t;
	}
	if (x1 < 0) {
		x1 += m0;
	}
	return x1;
}

long long gcd(long long n1, long long n2) {
	//return gcd of n1 and n2
	if (n2 == 0) return n1;
	n1 %= n2;
	return gcd(n2, n1);
}

int main(void) {
	int testCases;
	while (cin >> testCases) {
		for (int i = 0; i < testCases; i++) {
			vector<long long> A;
			vector<long long> B;
			//jeg må fjerne alternate
			for (int j = 0; j < 2; j++) {
				long long a_i, b_i;
				// her bytter jeg rekkefølgen
				cin >> b_i >> a_i;
				A.push_back(a_i);
				B.push_back(b_i);
			}
			bool impossible = false;
			long long x = A[0];
			long long y = B[0];
			for (int j = 1; j < 2; j++) {
				long long x_1 = A[j]; long long y_1 = B[j];
				long long divisor = gcd(x, A[j]);
				if ((y_1 - y) % divisor == 0) {
					long long z = (((y_1 - y) / divisor)*inverse(x / divisor, x_1 / divisor)) % (x_1 / divisor);
					y = x*z + y;
					x = (x / divisor)*x_1;
				}
				else {
					impossible = true;
				}
			}
			long long K = A[0]/gcd(A[0], A[1])*A[1];
			if (impossible) {
				cout << "no solution" << endl;
			}
			else {
				cout << (y + x) % x << " " << K << endl;
			}
		}
	}
	return 0;
}
