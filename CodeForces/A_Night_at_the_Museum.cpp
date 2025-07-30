#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    string s;
    cin >> s;

    int total_rotations = 0;
    char current = 'a';

    for (char c : s) {
        int diff = abs(c - current);
        total_rotations += min(diff, 26 - diff);
        current = c;
    }

    cout << total_rotations << endl;
    return 0;
}
