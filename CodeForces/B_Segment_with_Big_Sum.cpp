#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, s;
    cin >> n >> s;

    vector<long long> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int left = 0;
    long long sum = 0;
    int minLen = n + 1;

    for(int right = 0; right < n; right++){
        sum += arr[right];
        while(sum >= s){
            minLen = min(minLen, right - left + 1);
            sum -= arr[left];
            left++;
        }
    }

    if(minLen == n + 1)
        cout << -1 << endl;
    else
        cout << minLen << endl;

    return 0;
}
