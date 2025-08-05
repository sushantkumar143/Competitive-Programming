#include <iostream>
using namespace std;

int countOrdinaryNumbers(int n) {
    int count = 0;
    for (int d = 1; d <= 9; ++d) {
        int num = d;
        while (num <= n) {
            count++;
            num = num * 10 + d;
        }
    }
    return count;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << countOrdinaryNumbers(n) << endl;
    }
    return 0;
}
