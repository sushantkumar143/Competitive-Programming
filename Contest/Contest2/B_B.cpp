#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    multiset<int> mst;
    vector<int> ans;

    for (int i = 0; i < n; i++) {
        mst.insert(arr[i]);

        if (i >= k) {
            mst.erase(mst.find(arr[i - k]));
        }

        if (i >= k - 1) {
            auto it = mst.begin();
            advance(it, k / 2);
            if (k % 2 == 0) {
                auto it2 = it;
                --it2;
                ans.push_back((*it + *it2) / 2); 
            } else {
                ans.push_back(*it);
            }
        }
    }

    for (int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}
