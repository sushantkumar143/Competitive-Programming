#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;

    vector<long long> a(m);
    for (int i = 0; i < m; ++i)
        cin >> a[i];

    long long time = 0, curr = 1;
    for (int i = 0; i < m; ++i) {
        if (a[i] >= curr)
            time += a[i] - curr;
        else
            time += n - (curr - a[i]);
        curr = a[i];
    }

    cout << time << endl;
    return 0;
}
