#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    double c;
    cin >> c;

    double low = 0.0, high = c;
    while (high - low > 1e-7) {
        double mid = (low + high) / 2.0;
        double value = mid * mid + sqrt(mid);
        if (value < c)
            low = mid;
        else
            high = mid;
    }

    cout << fixed << setprecision(10) << low << endl;
    return 0;
}
