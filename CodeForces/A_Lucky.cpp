#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--){
        string n;
        cin >> n;
        int mid = n.length()/2;
        int left = 0;
        int right = 0;
        for(int i=0; i<mid; i++){
            left += n[i] - '0';
        }
        for(int i=mid; i<n.length(); i++){
            right += n[i] - '0';
        }

        if(left == right) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}
