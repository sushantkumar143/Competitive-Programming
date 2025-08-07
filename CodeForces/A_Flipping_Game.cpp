#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int total_ones = 0;
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 1) total_ones++;
    }

    int max_gain = -1e9, current_gain = 0;
    for (int i = 0; i < n; ++i) {
        int val = (a[i] == 0) ? 1 : -1;
        current_gain = max(val, current_gain + val);
        max_gain = max(max_gain, current_gain);
    }

    if (total_ones == n) {
        cout << n - 1 << endl;
    } 
    else {
        cout << total_ones + max_gain << endl;
    }

    return 0;
}
