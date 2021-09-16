#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
const long long big_divisor = 1000000007;

int power(long long x, unsigned int y, int p)
{
    int res = 1;     // Initialize result
 
    x = x % p; // Update x if it is more than or
                // equal to p
  
    if (x == 0) return 0; // In case x is divisible by p;
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

int main() {
    string sequence;
    cin >> sequence;
    long long ans = 0;

    long long num_question_mark = 0;
    long long num_zeros = 0;
    int n = sequence.length();

    for (int i = n-1; i >= 0; i--) {
        char bit = sequence[i];
        if (bit == '0') {
            num_zeros++;
        }
        else if (bit == '1') {
            ans = ans
                + num_zeros*power(2, num_question_mark, big_divisor)
                + num_question_mark*power(2, num_question_mark - 1, big_divisor);
            ans = ans % big_divisor;
        }
        else if (bit == '?') {
            ans = 2*ans
                + num_zeros*power(2, num_question_mark, big_divisor)
                + num_question_mark*power(2, num_question_mark - 1, big_divisor);
            ans = ans % big_divisor;
            num_question_mark++;
        }
    }

    cout << ans << endl;
}