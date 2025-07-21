#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int h, m;
        cin >> h >> m;
        int min = (23-h)*60 + 60-m;
        cout << min << '\n';
    }
    return 0;
}
