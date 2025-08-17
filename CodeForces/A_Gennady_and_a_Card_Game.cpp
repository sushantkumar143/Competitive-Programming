#include <bits/stdc++.h>
using namespace std;

int main() {
    string table;
    cin >> table;

    string hand[5];
    for (int i = 0; i < 5; i++) cin >> hand[i];

    char tableRank = table[0];
    char tableSuit = table[1];

    for (int i = 0; i < 5; i++) {
        if (hand[i][0] == tableRank || hand[i][1] == tableSuit) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;
}
