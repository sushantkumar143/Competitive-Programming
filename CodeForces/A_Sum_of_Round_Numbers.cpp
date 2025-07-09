#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> roundNumbers;
        int place = 1;

        while (n) {
            int digit = n % 10;
            if (digit != 0) {
                roundNumbers.push_back(digit * place);
            }
            place *= 10;
            n /= 10;
        }

        cout << roundNumbers.size() << '\n';
        reverse(roundNumbers.begin(), roundNumbers.end()); 
        for (int num : roundNumbers) {
            cout << num << " ";
        }
        cout << '\n';
    }

    return 0;
}
