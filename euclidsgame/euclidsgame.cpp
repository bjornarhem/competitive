// https://open.kattis.com/problems/euclidsgame

#include <algorithm>
#include <iostream>

using namespace std;

int myFunction(long long x, long long y, int moves) {
	if (max(x,y) >= 2*min(x,y) || x==y){
		return moves;
	}
	else{
		return myFunction(min(x,y), max(x,y)-min(x,y), moves+1);
	}
}

int main() {
	long long a,b;
	while (cin >> a >> b) {
		if(a != 0 && b != 0){
			int moves_to_winning_position = myFunction(a,b,0);
			if(moves_to_winning_position % 2 == 0){
		      	 	cout << "Stan wins" << endl;
			}
 			else{
				cout << "Ollie wins" << endl;
			}		
		}
	}
}	
