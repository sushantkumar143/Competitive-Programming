#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int upper_cnt = 0;
    int lower_cnt = 0;

    for (char ch : s) {
        if (isupper(ch)) {
            upper_cnt++;
        } else {
            lower_cnt++;
        }
    }

    if (upper_cnt > lower_cnt) {
        for (char &ch : s) ch = toupper(ch);
    } else {
        for (char &ch : s) ch = tolower(ch);
    }

    cout << s;
    return 0;
}
