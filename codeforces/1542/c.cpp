#include <iostream>
#include <vector>

using namespace std;

const long long divisor = 1000000007;

long long gcd(long long a, long long b) {
    // Euclid's algorithm
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return a*(b/gcd(a, b));
}

long long fsum(long long n) {
    // return sum_i n//lcm(1, ..., i)
    long long sum = 2*n % divisor;
    long long d = 2;
    long long i = 2;
    while (d <= n) {
        sum = (sum + n/d) % divisor;
        i++;
        d = lcm(d, i);
    }
    return sum;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        long long n;
        cin >> n;
        cout << fsum(n) << endl;
    }
}