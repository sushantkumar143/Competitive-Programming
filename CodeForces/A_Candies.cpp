#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        for (int k = 2; ; ++k) {
            int64_t sum = (1LL << k) - 1; 
            if (n % sum == 0) {
                cout << n / sum << endl;
                break;
            }
        }
    }

}
