#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    int cnt = 0;
    int th = arr[k-1];
    for(int i=0; i<n; i++){
        if(arr[i] >= th && arr[i]>0) cnt++;
    }

    cout << cnt;
}