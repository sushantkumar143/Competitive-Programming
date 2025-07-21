// If the total sum is odd, it's impossible for two numbers to have the same parity
// and sum to an odd number.
// (even + even = even)
// (odd + odd = even)
// (even + odd = odd)
// So, if S_blue and S_red have the same parity, their sum S_total must be even.
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    long long total_sum = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        total_sum += a[i];
    }

    if (total_sum % 2 != 0) {
        cout << "NO\n";
    } 
    else {
        cout << "YES\n";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve(); 
    }
}