#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    int zeros = 0;
    int ones = 0;
    for(char i : s){
        if(i == '0') zeros++;
        else ones++;
    }

    cout << abs(ones - zeros);
}