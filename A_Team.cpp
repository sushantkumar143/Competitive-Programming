#include<bits/stdc++.h>
using namespace std;

// THIS IS THE SECOND FILE IN WHICH I HAD MADE CHANGES TO DEMOSTRATE IN CA-1 OF LINUX
// IT IS FINE TO MAKE CHANGES HERE

int main(){
    int n;
    cin >> n;
    int cnt = 0;

    while(n--){
        int a,b,c;
        cin >> a >> b >> c;
        int temp = 0;
        if(a==1) temp++;
        if(b==1) temp++;
        if(c==1) temp++;

        if(temp >= 2) cnt++;
    }
    cout << cnt;
}
