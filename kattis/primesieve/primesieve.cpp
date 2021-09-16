// https://open.kattis.com/problems/primesieve

#include <iostream>
#include <vector>

using namespace std;

int main(){
    long n, q;
    while(cin >> n >> q){
        vector<bool> nums = {};
        for(long i = 1; i<n+1; i++){
            nums.push_back(1);
        }
        nums[0]=0;
        long primes = 0;
        for(long i = 1; i<n+1; i++){
            if(nums[i-1]==1){
                primes++;
                if(i*i<n+1){    
                    for(long j = i*i; j<n+1; j+=i){
                        nums[j-1]=0;
                    }
                }
            }
        }
        cout << primes << endl;
        for(int i=0;i<q;i++){
            long x;
            cin >> x;
            cout << nums[x-1] << endl;
        }
    }
}
