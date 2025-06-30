#include <bits/stdc++.h>
using namespace std;

bool isLucky(int num) {
    while(num) {
        int digit = num % 10;
        if(digit != 4 && digit != 7)
            return false;
        num /= 10;
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    for(int i = 1; i <= n; ++i) {
        if(isLucky(i) && n % i == 0) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;
}
