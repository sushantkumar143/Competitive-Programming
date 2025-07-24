#include <bits/stdc++.h>
using namespace std;

// void helper(vector<int>& arr, int& cnt, int target, int index){
//     if(index == arr.size() || target<0) return;

//     if(target == 0) cnt++;
//     helper(arr, cnt, target, index+1);
//     helper(arr, cnt, target-arr[index], index+1);
// }

// int main() {
//     int n, k;
//     cin >> n >> k;

//     vector<int> arr(n);
//     for(auto& x : arr) cin >> x;

//     int cnt = 0;
//     helper(arr, cnt, k, 0);
//     cout << cnt;
// }


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long x;
    cin >> n >> x;

    vector<long long> a(n);
    for(auto& val : a) cin >> val;

    unordered_map<long long, int> prefixCount;
    prefixCount[0] = 1;  

    long long curr_sum = 0;
    long long result = 0;

    for(int i = 0; i < n; ++i) {
        curr_sum += a[i];
        result += prefixCount[curr_sum - x];
        prefixCount[curr_sum]++;
    }

    cout << result << "\n";
}
