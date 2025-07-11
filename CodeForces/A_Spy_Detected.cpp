#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int repeating = arr[0];
        if(arr[0] == arr[1]) repeating = arr[0];
        else if(arr[1] == arr[2]) repeating = arr[1];
        else repeating = arr[2]; 

        for(int i = 0; i < n; i++) {
            if(arr[i] != repeating) {
                cout << i + 1 << '\n'; 
                break;
            }
        }
    }

    return 0;
}
