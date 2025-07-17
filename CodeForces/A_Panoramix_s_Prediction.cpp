#include <iostream>
using namespace std;

bool isPrime(int num) {
    for (int i = 2; i * i <= num; i++)
        if (num % i == 0)
            return false;
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    int nextPrime = n + 1;
    while (!isPrime(nextPrime)) {
        nextPrime++;
    }

    if (nextPrime == m)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
