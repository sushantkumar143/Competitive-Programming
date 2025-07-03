#include <iostream>
#include <string>
using namespace std;

bool isLuckyNumber(int count) {
    if (count == 0) return false;
    while (count > 0) {
        int digit = count % 10;
        if (digit != 4 && digit != 7)
            return false;
        count /= 10;
    }
    return true;
}

int main() {
    string n;
    cin >> n;

    int luckyDigitCount = 0;
    for (char ch : n) {
        if (ch == '4' || ch == '7') {
            luckyDigitCount++;
        }
    }

    if (isLuckyNumber(luckyDigitCount)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
