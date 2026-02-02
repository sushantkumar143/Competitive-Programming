#include<bits/stdc++.h>
using namespace std;

void fun(string s, int& x) {
    if(s == "++X") ++x;
    else if(s == "X++") x++;
}
 
int main() {
    int t;
    cin >> t;
    int x = 0;

    while(t--) {
        string s;
        cin >> s;

        if(s == "++X") ++x;
        else if(s == "X++") x++;
        else if(s == "--X") --x;
        else if(s == "X--") x--;
    }

    cout << x;
}