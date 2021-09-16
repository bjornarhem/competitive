#include <iostream>
#include <string>

using namespace std;

void guess(int low, int high) {
    int mid = (high + low) / 2;
    cout << mid << endl;
    string response;
    cin >> response;
    if (response == "lower") guess(low, mid-1);
    else if (response == "higher") guess(mid+1, high);
}

int main () {
    guess(1, 1000);
    return 0;
}