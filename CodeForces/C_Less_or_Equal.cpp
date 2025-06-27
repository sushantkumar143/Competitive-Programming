#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, k;
    cin >> n >> k;

    vector<long long> arr(n);
    long long mx = 0;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        if(arr[i]>mx) mx = arr[i];
    }
    sort(arr.begin(), arr.end());

    if(!k){
        if(arr[0]==1){
            cout<<"-1";
        }
        else{
            cout<<arr[0]-1;
        }
        return 0;
    }
    if(k==n){
        cout<<arr[n-1]+1;
        return 0;
    }
    if(arr[k]!=arr[k-1]){
        cout<<arr[k-1]+1;
    }
    else{
        cout<<-1;
    }
}