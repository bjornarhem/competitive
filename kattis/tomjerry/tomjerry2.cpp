#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <algorithm>

using namespace std;

const long long big_divisor = 1000000007;

bool has_cheese(int x, int y, set<pair<int, int>> set) {
    return set.find(make_pair(x, y)) != set.end();
}

// Function for extended Euclidean Algorithm
long long gcdExtended(long long a, long long b, long long* x, long long* y);
 
// Function to find modulo inverse of a
long long modInverse(long long a, long long m)
{
    long long x, y;
    long long g = gcdExtended(a, m, &x, &y);
    return (x % m + m) % m;
}
 
// Function for extended Euclidean Algorithm
long long gcdExtended(long long a, long long b, long long* x, long long* y)
{
     
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
     
    // To store results of recursive call
    long long x1, y1;
    long long gcd = gcdExtended(b % a, a, &x1, &y1);
 
    // Update x and y using results of recursive
    // call
    *x = y1 - (b / a) * x1;
    *y = x1;
 
    return gcd;
}

long long seq_product(long long n, long long k) {
    // returns n*(n-1)*...*k mod big_divisor
    if (n==k) {
        return 1;
    }
    else {
        return n*seq_product(n-1, k) % big_divisor;
    }
}

long long factorial(long long n) {
    return seq_product(n, 0);
}

long long binomial(long long n, long long k) {
    if (k < 0 || k > n) {
        return 0;
    }
    return seq_product(n, n-k)*modInverse(factorial(k), big_divisor) % big_divisor;
}

long long num_paths(pair<int, int> p1, pair<int, int> p2) {
    int x1 = p1.first;
    int y1 = p1.second;
    int x2 = p2.first;
    int y2 = p2.second;
    return binomial(x2 - x1 + y2 - y1, x2 - x1);
}

long long cheese_paths(vector<pair<int, int>> cheese, pair<int, int> start, int index, int w, int h) {
    if (index >= cheese.size()) {
        return 0;
    }
    return ((
        num_paths(start, cheese[index])*num_paths(cheese[index], make_pair(w-1, h-1))
        + cheese_paths(cheese, start, index + 1, w, h)
        - num_paths(start, cheese[index])*cheese_paths(cheese, cheese[index], index+1, w, h)
    ) % big_divisor + big_divisor) % big_divisor;
}

/*
long long cheese_paths(vector<pair<int, int>> cheese, int index, int w, int h) {
    long long num_cheese_paths = 0;
    if (index == -1) {
        for (int i = 0; i < cheese.size(); i++) {
            num_cheese_paths = (
                num_cheese_paths 
                + num_paths(make_pair(0, 0), cheese[i])*cheese_paths(cheese, i, w, h)
            ) % big_divisor;
        }
    }
    else {
        for (int i = index + 1; i < cheese.size(); i++){
            num_cheese_paths = (
                num_cheese_paths 
                + num_paths(cheese[index], cheese[i])*cheese_paths(cheese, i, w, h)
            ) % big_divisor;
        }
        num_cheese_paths = (
            num_cheese_paths 
            + num_paths(cheese[index], make_pair(w-1, h-1))
        ) % big_divisor;
    }
    return num_cheese_paths;
}
*/

int main() {
    int w, h;
    cin >> w >> h;
    int n;
    cin >> n;
    vector<pair<int, int>> cheese (n);
    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        cheese[i] = make_pair(x-1, y-1);
    }

    sort(cheese.begin(), cheese.end());

    cout << cheese_paths(cheese, make_pair(0, 0), 0, w, h) << endl;
}