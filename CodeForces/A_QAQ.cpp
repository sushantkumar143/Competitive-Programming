#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();

    // Count total Qs
    int totalQ = 0;
    for (char c : s)
        if (c == 'Q') totalQ++;

    int leftQ = 0, answer = 0;

    for (char c : s) {
        if (c == 'Q') {
            leftQ++;
        } else if (c == 'A') {
            int rightQ = totalQ - leftQ; 
            answer += leftQ * rightQ; 
        }
    }

    cout << answer << "\n";
    return 0;
}
