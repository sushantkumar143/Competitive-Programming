#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;

    long long kmax = (n - m + 1) * (n - m) / 2;

    long long q = n / m;  
    long long r = n % m;  
    long long kmin = r * (q + 1) * q / 2 + (m - r) * q * (q - 1) / 2;

    cout << kmin << " " << kmax << endl;
    return 0;
}
