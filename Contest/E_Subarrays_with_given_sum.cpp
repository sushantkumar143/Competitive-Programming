#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ,k;
    cin >> n >> k;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    int left = 0;
    int sm = 0;
    int cnt = 0;
    for(int right = 0; right<n; right++){
        sm += arr[right];
        while(left <= right && sm > k){
            sm -= arr[left++];
        }
        if(sm == k){
            cnt++;
            sm -= arr[left++];
        }
    }   
    
    cout << cnt;
}