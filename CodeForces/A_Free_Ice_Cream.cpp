#include <bits/stdc++.h>
using namespace std;

int main() {
    long long t, n;
    cin >> t >> n;

    int remaining = 0;

    while(t--) {
        char ch;
        cin >> ch;
        long long num;
        cin >> num;

        if(ch == '+') n += num;
        else{
            if(n >= num) n -= num;
            else remaining++;
        }
    }

    cout << n << ' ' << remaining;

}