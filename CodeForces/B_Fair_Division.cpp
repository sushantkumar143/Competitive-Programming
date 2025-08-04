#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        int one = 0, two = 0, total = 0;

        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            total += x;
            if(x == 1) one++;
            else two++;
        }

        if(total % 2 != 0) {
            cout << "NO\n";
        } 
        else {
            int half = total / 2;

            if (half % 2 != 0 && one == 0) {
                cout << "NO\n";
            } 
            else {
                cout << "YES\n";
            }
        }
    }
}
