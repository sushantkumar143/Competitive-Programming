#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(long long n) {
    if(n < 2) return false;
    for(long long i = 2; i * i <= n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        long long n;
        cin >> n;
        long long root = sqrt(n);

        if(root * root == n && isPrime(root)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
