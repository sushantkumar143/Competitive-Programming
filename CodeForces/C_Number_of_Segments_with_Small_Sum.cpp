#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, s;
    cin >> n >> s;
    vector<long long> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    long long left = 0;
    long long cnt = 0;
    long long sum = 0;
    
    for(int right=0; right<n; right++){
        sum += arr[right];
        while(sum > s){
            sum -= arr[left];
            left++;
        }
        cnt += (right-left+1);
    }
    cout << cnt;
}