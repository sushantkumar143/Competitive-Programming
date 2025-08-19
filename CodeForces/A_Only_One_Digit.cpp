#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        int mini = n%10;
        while(n) {
            int k = n%10;
            mini = min(k, mini);
            n /= 10;
        }

        cout << mini << '\n';
    }
}