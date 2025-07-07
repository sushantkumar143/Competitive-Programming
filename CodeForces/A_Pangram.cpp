#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int arr[26] = {0};

    for (char &ch : s) {
        ch = tolower(ch);
    }

    for (char ch : s) {
        if (ch >= 'a' && ch <= 'z') {
            arr[ch - 'a']++;
        }
    }

    for (int i : arr) {
        if (i == 0) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
    return 0;
}
