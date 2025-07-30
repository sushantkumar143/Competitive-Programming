#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int cnt = n; 
    int rem = n; 

    while (rem >= k) {
        int temp = rem / k;
        cnt += temp;
        rem = temp + (rem % k); 
    }

    cout << cnt;
    return 0;
}
