#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;

        int arr[26] = {0};
        for(char ch : s){
            arr[ch-'A']++;
        }
        int cnt = 0;
        for(int i : arr){
            if(i != 0){
                cnt += i+1;
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}
