#include<bits/stdc++.h>
using namespace std;

bool canPlaceCows(int mid, vector<int> arr, int k){
    int cnt = 1;
    int lastPlaced = arr[0];
    int n = arr.size();
    for(int i=0; i<n; i++){
        if(arr[i]-lastPlaced >= mid){
            cnt++;
            lastPlaced = arr[i];
        }
        if(cnt >= k) return true;
    }
    return false;
}

int main(){
    long long n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int left = 1;
    long long right = arr[n-1]-arr[0];
    long long ans = 0;
    while(left <= right){
        int mid = (left+right)/2;
        if(canPlaceCows(mid, arr, k)){
            ans = mid;
            left = mid+1;
        }
        else right = mid-1;
    }
    cout << ans;
}