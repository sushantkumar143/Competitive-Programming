#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> cubes(n);
    for (int i = 0; i < n; ++i)
        cin >> cubes[i];

    multiset<int> arr;

    for (int i = 0; i < n; ++i) {
        auto it = arr.upper_bound(cubes[i]);
        if (it != arr.end()) {
            arr.erase(it);
        }
        arr.insert(cubes[i]);
    }

    cout << arr.size() << endl;
    return 0;
}
