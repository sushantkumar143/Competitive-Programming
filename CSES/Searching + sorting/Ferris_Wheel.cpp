#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    
    vector<int> arr(n);
    for(int& x : arr) {
        cin >> x;
    }

    sort(arr.begin(), arr.end());

    int i=0; 
    int j = n-1;
    int cnt = 0;
    while(i <= j) {
        if(arr[i] + arr[j] <= x) {
            cnt++;
            i++;
            j--;
        }
        else {
            cnt++;
            j--;
        }
    }

    cout << cnt;

    return 0;
}