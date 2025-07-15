#include <bits/stdc++.h>
using namespace std;

int main() {
    string num;
    cin >> num;

    for (int i = 0; i < num.size(); ++i) {
        int digit = num[i] - '0';
        int flipped = 9 - digit;

        if (i == 0 && digit == 9) continue;

        if (flipped < digit) {
            num[i] = (char)(flipped + '0');
        }
    }

    cout << num << '\n';
    return 0;
}
