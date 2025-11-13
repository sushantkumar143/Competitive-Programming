#include<bits/stdc++.h>
using namespace std;

// Here i had made changes to demostrate in CA - 1 of LINUX

int main(){
    int n;
    cin >> n;
    
    int count = 0;
    while(n--){
        string s;
        cin >> s;
        if(s == "X++" || s == "++X") count++;
        else count--;
    }
    cout << cnt;

    return 0;
}
