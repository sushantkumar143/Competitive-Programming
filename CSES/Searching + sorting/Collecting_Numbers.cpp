#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
    }

    sort(arr.begin(), arr.end());
    int cnt = 1;

    for(int i=1; i<n; i++) {
        if(arr[i-1].second > arr[i].second) cnt++;
    }
    cout << cnt;
}