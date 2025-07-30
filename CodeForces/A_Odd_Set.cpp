#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int even = 0;
        int odd = 0;
        for(int i=0; i<n*2;  i++){
            int data;
            cin >> data;
            if(data % 2 == 0) even++;
            else odd++;
        }
        if(even == odd) cout << "Yes\n";
        else cout << "No\n"; 
    }
}