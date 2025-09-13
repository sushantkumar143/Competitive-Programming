#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    if (!(cin >> n)) return 0;
    
    vector<int> primeFactorCount(n + 1, 0);
    
    for (int p = 2; p <= n; ++p) {
        if (primeFactorCount[p] == 0) { 
            for (int multiple = p; multiple <= n; multiple += p) {
                primeFactorCount[multiple] += 1;
            }
        }
    }
    
    int answer = 0;
    for (int i = 2; i <= n; ++i) {
        if (primeFactorCount[i] == 2) ++answer;
    }
    
    cout << answer << '\n';
    return 0;
}
