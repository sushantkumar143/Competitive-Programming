#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        int cost = 0;

        if(a < b){
            for(int i = a; i < b; i++){
                if(i % 2 == 0) cost += min(x, y);
                else cost += x;
            }
        }
        else if(a == b + 1 && a % 2 == 1){
            cost = y;
        }
        else if(a == b){
            cost = 0;
        }
        else{
            cost = -1;
        }

        cout << cost << '\n';
    }
}
