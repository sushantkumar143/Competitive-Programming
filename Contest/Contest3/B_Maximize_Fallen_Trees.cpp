#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> trees(n);
    for (int i = 0; i < n; ++i) {
        cin >> trees[i].first >> trees[i].second;
    }
    if (n == 1) {
        cout << 1 << '\n'; 
        return 0;
    }
    int count = 2; 
    int last = trees[0].first; 
    for (int i = 1; i < n - 1; ++i) {
        int x = trees[i].first;
        int h = trees[i].second;
        if (x - h > last) {
            count++;
            last = x;
        }
        else if (x + h < trees[i + 1].first) {
            count++;
            last = x + h;
        }
        else {
            last = x;
        }
    }
    cout << count << '\n';
}
