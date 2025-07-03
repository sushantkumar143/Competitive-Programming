#include <iostream>
#include <string>
#include<bits/stdc++.h>
using namespace std;

bool check(int n) {
    int arr[10] = {0};
    while (n) {
        int digit = n % 10;
        if (arr[digit]) return false;
        arr[digit] = 1;
        n /= 10;
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    int ans = 0;
    int t = n+1;

    while(t){        
        if(check(t)){
            cout << t;
            return 0;
        }
        t++;
    }

    cout << ans;
}