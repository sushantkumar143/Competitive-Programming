#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, s;
        cin >> n >> s;
        int arr[n];
        for(int i=0; i<n; i++) cin >> arr[i];

        int a = min(abs(arr[0] - s), abs(arr[n-1]-s));
        int b = abs(arr[n-1] - arr[0]);
        cout << a+b << "\n";
    }
}