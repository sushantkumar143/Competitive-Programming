#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));

        int maxi = 0;
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                cin >> a[i][j];
                maxi = max(a[i][j], maxi);
            }
        }
        
        vector<int> rowcount(n,0);
        vector<int> colcount(m,0);
        int cnt = 0;
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                if(a[i][j] == maxi){
                    rowcount[i]++;
                    colcount[j]++;
                    cnt++;
                }
            }
        }

        bool flag = false;

        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                int total = rowcount[r] + colcount[c] - (a[r][c]==maxi);
                if(total == cnt){
                    flag = true;
                } 
            }
        }

        if(!flag){
            cout << maxi << "\n";
        }
        else
            cout << maxi-1 << "\n";

    }

    return 0;
}
