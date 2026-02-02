#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    
    vector<pair<int, int>> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i].first;
        arr[i].second = i+1;
    }

    sort(arr.begin(), arr.end());
    
    int left = 0;
    int right = arr.size()-1;
    while(left < right) {
        if(arr[left].first + arr[right].first == x) {
            cout << arr[right].second << " " << arr[left].second;
            return 0;
        }
        else if(arr[left].first + arr[right].first < x) {
            left++;
        }
        else right--;
    }
    cout << "IMPOSSIBLE";
    return 0;
}