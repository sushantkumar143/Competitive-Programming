#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;

    int sum = 0;
    for(int i=0; i<n; i++){
        int data;
        cin >> data;
        sum += data;
    }

    double ans = (double)sum/n;

    cout << fixed << setprecision(12) << ans;
}
