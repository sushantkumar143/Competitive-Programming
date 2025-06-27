#include<iostream>
using namespace std;
#include<bits/stdc++.h>

// 1 - Based Indexing

int main(){
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<int> prefix(n+1, 0);
    int sum = 0;
    for(int i=0; i<n; i++){
        prefix[i] = sum;
        sum += v[i];
    }    

    for(int i=0; i<=n; i++) cout << prefix[i] << " ";

    int left, right;
    cin >> left >> right;

    int ans = prefix[right] - prefix[left-1];
    cout << ans;
}