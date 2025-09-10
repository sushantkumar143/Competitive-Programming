#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        long long x = 0;
        int i = 1; 
        string last;

        while (true) {
            long long move = 2LL * i - 1;
            if (i % 2 == 1) { 
                x -= move;
                if (abs(x) > n) {
                    last = "Sakurako";
                    break;
                }
            } 
            else {
                x += move;
                if (abs(x) > n) {
                    last = "Kosuke";
                    break;
                }
            }
            i++;
        }

        cout << last << "\n";
    }
    return 0;
}
