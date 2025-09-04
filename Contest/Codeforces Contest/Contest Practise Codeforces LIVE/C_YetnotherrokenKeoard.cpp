#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        string result;
        // Stacks to track positions of last lowercase & uppercase
        stack<int> lower, upper;

        for (char c : s) {
            if (c == 'b') {
                if (!lower.empty()) {
                    int pos = lower.top();
                    lower.pop();
                    result.erase(pos, 1);
                    // Update positions (since erase shifts indices)
                    stack<int> tmp;
                    while (!lower.empty()) {
                        int idx = lower.top(); lower.pop();
                        if (idx > pos) tmp.push(idx - 1);
                        else tmp.push(idx);
                    }
                    while (!tmp.empty()) { lower.push(tmp.top()); tmp.pop(); }

                    stack<int> tmp2;
                    while (!upper.empty()) {
                        int idx = upper.top(); upper.pop();
                        if (idx > pos) tmp2.push(idx - 1);
                        else tmp2.push(idx);
                    }
                    while (!tmp2.empty()) { upper.push(tmp2.top()); tmp2.pop(); }
                }
            } 
            else if (c == 'B') {
                if (!upper.empty()) {
                    int pos = upper.top();
                    upper.pop();
                    result.erase(pos, 1);
                    // Update positions
                    stack<int> tmp;
                    while (!lower.empty()) {
                        int idx = lower.top(); lower.pop();
                        if (idx > pos) tmp.push(idx - 1);
                        else tmp.push(idx);
                    }
                    while (!tmp.empty()) { lower.push(tmp.top()); tmp.pop(); }

                    stack<int> tmp2;
                    while (!upper.empty()) {
                        int idx = upper.top(); upper.pop();
                        if (idx > pos) tmp2.push(idx - 1);
                        else tmp2.push(idx);
                    }
                    while (!tmp2.empty()) { upper.push(tmp2.top()); tmp2.pop(); }
                }
            } 
            else {
                int pos = result.size();
                result.push_back(c);
                if (islower(c)) lower.push(pos);
                else upper.push(pos);
            }
        }

        cout << result << "\n";
    }
    return 0;
}
