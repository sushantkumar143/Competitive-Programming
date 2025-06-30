#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    int cnt = 0;
    while(n--){
        string s;
        cin >> s;
        if(s == "X++" || s == "++X") cnt++;
        else cnt--;
    }
    cout << cnt;
}