#include <bits/stdc++.h>
using namespace std;

bool helper(vector<int>& arr, int index, int sum) {
    if(index == arr.size()) {
        return (sum % 360 + 360) % 360 == 0;
    }

    return helper(arr, index + 1, sum + arr[index]) || 
           helper(arr, index + 1, sum - arr[index]);
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(auto& x : arr) cin >> x;

    if(helper(arr, 0, 0)) {
        cout << "YES\n";
    } 
    else {
        cout << "NO\n";
    }

    return 0;
}
