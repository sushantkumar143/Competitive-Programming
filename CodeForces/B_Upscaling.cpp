#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int size = 2 * n;

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (((i / 2) + (j / 2)) % 2 == 0)
                    cout << "#";
                else
                    cout << ".";
            }
            cout << "\n";
        }
    }
    return 0;
}
