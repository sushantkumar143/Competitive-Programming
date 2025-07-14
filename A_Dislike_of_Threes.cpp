#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t; 

    while(t--){
        int n;
        cin >> n;
        int k = 1;
        while(n){
            if(k % 3 != 0 && k % 10 != 3){
                n--;
            }
            k++;
        }
        cout << k - 1 << '\n';
    }
}
