#include<bits/stdc++.h>
using namespace std;

// LEETCODE - 258  -> Count Digits

int main(){
    int n;
    cin >> n ;
    // int sm = 0;
    // while(n){
    //     int d = n%10;
    //     sm += d;
    //     n /= 10;
    //     if(n == 0 && sm>=10){
    //         n = sm;
    //         sm = 0;
    //     }
    // }
    // cout << sm;
    cout << 1 + (n-1) % 9;
}