#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);

        for(int i=0; i<n; i++) cin >> arr[i];

        int i = 0;
        int j = n-1;
        vector<int> ans;
        
        while(i <= j){
            ans.push_back(arr[i++]);
            ans.push_back(arr[j--]);
        }
        if(n%2 != 0) ans.pop_back();

        for(int i : ans) cout << i << ' ';
        cout << '\n';
    }
}