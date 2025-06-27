#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> arr1(n);
    vector<int> arr2(m);

    for (int i = 0; i < n; i++) cin >> arr1[i];
    for (int i = 0; i < m; i++) cin >> arr2[i];

    vector<int> ans(m);
    int p1 = 0;

    for (int i = 0; i < m; i++) {
        while (p1 < n && arr1[p1] < arr2[i]) {
            p1++;
        }
        ans[i] = p1;
    }

    for (int i = 0; i < m; i++) cout << ans[i] << " ";
    cout << endl;

    return 0;
}
