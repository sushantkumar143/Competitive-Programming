#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> arr1(n);
    vector<int> arr2(m);

    for (int i = 0; i < n; i++) cin >> arr1[i];
    for (int i = 0; i < m; i++) cin >> arr2[i];

    vector<int> ans;
    int left = 0, right = 0;

    while (left < n && right < m) {
        if (arr1[left] <= arr2[right]) {
            ans.push_back(arr1[left]);
            left++;
        } else {
            ans.push_back(arr2[right]);
            right++;
        }
    }

    while (left < n) {
        ans.push_back(arr1[left++]);
    }

    while (right < m) {
        ans.push_back(arr2[right++]);
    }

    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
