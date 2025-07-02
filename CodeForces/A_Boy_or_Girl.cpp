#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    int n = s.length();
    int arr[26] = {0};

    for(char ch : s){
        arr[ch-97]++;
    }
    
    int cnt = 0;
    for(int i : arr){
        if(i > 0) cnt++;
    }
    
    if(cnt%2 == 0) cout << "CHAT WITH HER!";
    else cout << "IGNORE HIM!";
}