#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int k, n;
    cin >> k >> n;
    vector<long long> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long low = 0, high = 1e12;
    long long ans = 0;

    while (low <= high) {
        long long mid = (low + high) / 2;
        long long students = 0;
        
        for (int i = 0; i < n; i++) {
            students += min(a[i], mid);
        }

        if (students >= mid * k) {
            ans = mid;     
            low = mid + 1; 
        } else {
            high = mid - 1; 
        }
    }

    cout << ans << endl;
    return 0;
}
