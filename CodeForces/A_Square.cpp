#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int x[4];
        int y[4];

        for(int i=0; i<4; i++){
            cin >> x[i] >> y[i];
        }

        int side = x[0] == x[1] ? abs(x[0]-x[2]) : abs(x[0]-x[1]);
        cout << side*side << '\n';
    }
}