// https://open.kattis.com/problems/arrangingwine

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


long long divisor = pow(10,9) + 7;



// C++ program to find modular inverse of a under modulo m 
// This program works only if m is prime. 
  
// To compute x raised to power y under modulo m 
long long power(long long x, unsigned long long y, unsigned long long m); 
  
// Function to find modular inverse of a under modulo m 
// Assumption: m is prime 
long long modInverse(long long a, long long m) 
{ 
        // is a^(m-2) mode m 
        return power(a, m-2, m); 
} 
  
// To compute x^y under modulo m 
long long power(long long x, unsigned long long y, unsigned long long m) 
{ 
    if (y == 0) 
        return 1; 
    long long p = power(x, y/2, m) % m; 
    p = (p * p) % m; 
  
    return (y%2 == 0)? p : (x * p) % m; 
} 



long long modInverseDivisor(long long a) { return modInverse(a, divisor); }


long long modInverse2(long long a, long long m){
	if(a==1){
		return 1;
	}
	else{
		long long new_inv = modInverse2(m%a, a);
		return (1-m*new_inv)/a;
	}
}


vector<long long> bin_co_n_x(long long n){
	vector<long long> row (n+1);
	row[0] = 1;
	for(long long j = 0; j<n; j++){
		row[j+1] = (row[j]*(n-j)) % divisor;
		// row[j+1] = (row[j+1]*modInverseDivisor(j+1)) % divisor;
		row[j+1] = (row[j+1]*modInverse2(j+1, divisor)) % divisor;
	}
	return row;
}

vector<long long> bin_co_kx_k(long long k, long long max){
	vector<long long> row (max+1);
	row[0] = 1;
	for(long long i = 0; i<max; i++){
		row[i+1] = (row[i]*(k+i+1)) % divisor;
		// row[i+1] = (row[i+1]*modInverseDivisor(i+1)) % divisor;
		row[i+1] = (row[i+1]*modInverse2(i+1, divisor)) % divisor;
	}
	return row;
}

int main(){
	long long R, W, d;
	while(cin >> R >> W >> d){
		if(R==0){
			cout << 1 << endl;
		}
		else if(W==0){
			if(R>d){
				cout << 0 << endl;
			}
			else{
				cout << 1 << endl;
			}
		}
		else{

			// (W)C(l), where l is the list index
			vector<long long> bin_co_list_1 = bin_co_n_x(W);
			
			// (W-1+l)C(W-1), where l is the list index and l<=R
			vector<long long> bin_co_list_2 = bin_co_kx_k(W-1,R);
			
			long long sum = 0;
			for(long long i = R-d; i<=R; i++){
				for(long long j = 0; (0 <= i - j*(d+1)) && (j <= W); j++){
					// (-1)^j = 1-2*(j%2)
					sum = (sum + bin_co_list_1[j]*(1-2*(j%2))*bin_co_list_2[i-j*(d+1)]) % divisor;
				}
			}
			cout << (sum+divisor)%divisor << endl;
		}
	}
}
