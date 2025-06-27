#include <iostream>
using namespace std;

int main() {
    long long n, m, a;
    cin >> n >> m >> a;

    long long tiles_in_row = (n + a - 1) / a;
    long long tiles_in_col = (m + a - 1) / a;

    cout << tiles_in_row * tiles_in_col << endl;

    return 0;
}
