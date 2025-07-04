#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    for(int i=1; i<=n; i++){
        int idx = i%2 == 0 ? 0 : 1;
        if(idx == 1){
            cout << "I hate ";
        }
        else if(idx == 0){
            cout << "I love ";
        }

        if(i < n) cout << "that ";
    }

    cout << "it";
}
