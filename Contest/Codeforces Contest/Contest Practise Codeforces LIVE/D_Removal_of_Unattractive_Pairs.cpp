#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        stack<char> st;
        for (char c : s) {
            if (!st.empty() && st.top() != c) {
                st.pop();
            } else {
                st.push(c);
            }
        }
        cout << st.size() << "\n";
    }
    return 0;
}
