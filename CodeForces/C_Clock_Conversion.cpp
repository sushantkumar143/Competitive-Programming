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

        int hr = stoi(s.substr(0, 2));
        string minuteStr = s.substr(3, 2);
        string ans;

        if (hr == 0) {
            ans = "12:" + minuteStr + " AM";
        }
        else if (hr == 12) {
            ans = "12:" + minuteStr + " PM";
        }
        else if (hr > 12) {
            if (hr - 12 < 10) ans = "0" + to_string(hr - 12) + ":" + minuteStr + " PM";
            else ans = to_string(hr - 12) + ":" + minuteStr + " PM";
        }
        else { 
            if (hr < 10) ans = "0" + to_string(hr) + ":" + minuteStr + " AM";
            else ans = to_string(hr) + ":" + minuteStr + " AM";
        }

        cout << ans << '\n';
    }
}
