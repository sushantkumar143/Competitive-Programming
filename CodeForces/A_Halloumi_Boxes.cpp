#include <iostream>
#include<vector>
using namespace std;

bool isSorted(vector<int> arr){
    int n = arr.size();
    for(int i=1; i<n; i++){
        if(arr[i-1] > arr[i]) return false;
    }
    return true;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, x;
        cin >> n >> x; 
        vector<int> arr(n);
        for(auto& x : arr) cin >> x;

        if (x >= 2) {
            cout << "YES" << endl;
        } 
        if(x == 1){
            if(isSorted(arr)) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}
