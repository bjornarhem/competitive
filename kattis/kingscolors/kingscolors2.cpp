// https://open.kattis.com/problems/kingscolors

#include <iostream>
#include <vector>
using namespace std;
long long divisor = 1000000007;
long long mod_pow(long long a, long long p) {
if (p == 0) {
return 1;
}
if (p == 1) {
return a % divisor;
}
else {
long long x = mod_pow(a, p / 2);
x = x*x % divisor;
return x*mod_pow(a, p % 2) % divisor;
}
}
long long binom(long long n, long long r) {
if (r > n / 2)
r = n - r;
long long ans = 1;
for (long long i = n; i > n - r; i--) {
ans = ans*i % divisor;
ans = ans*mod_pow(1 + n - i, divisor - 2) % divisor;
}
return ans;
}
long long function(long long n, long long k, long long m, vector<long long> k_binoms) {
if (m == 1) {
return 0;
}
else {
long long x = k_binoms[m]*m % divisor;
x = x*mod_pow(m - 1, n - 1) % divisor;
long long y = function(n, k, m - 1, k_binoms) % divisor;
return (x - y) % divisor;
}
}
int main()
{
long long n, k;
cin >> n >> k;
vector<long long> k_binoms;
k_binoms.push_back(1);
for (int i = 1; i <= k; i++) {
long long x = k_binoms[i - 1] * (k - (i-1)) % divisor;
long long y = x*mod_pow(i, divisor - 2) % divisor;
k_binoms.push_back(y);
}
cout << (function(n, k, k, k_binoms) + divisor)%divisor << endl;
}
