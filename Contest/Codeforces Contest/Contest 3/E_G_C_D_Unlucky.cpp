#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
int computeGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
bool isValidArray(const vector<int>& p, const vector<int>& s, int n) {
    for (int i = 0; i < n; ++i) {
        int g = computeGCD(p[i], s[i]);
        if (p[i] != g && s[i] != g)
            return false;
    }
    return true;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n), s(n);
        for (int i = 0; i < n; ++i) cin >> p[i];
        for (int i = 0; i < n; ++i) cin >> s[i];

        cout << (isValidArray(p, s, n) ? "YES" : "NO") << "\n";
    }
    return 0;
}