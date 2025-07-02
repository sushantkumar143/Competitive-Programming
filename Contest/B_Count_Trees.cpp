#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<char>> arr(n+1, vector<char>(n+1));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }

    vector<vector<int>> prefix(n+1, vector<int>(n+1, 0));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int tree = arr[i-1][j-1] == '*' ? 1 : 0;
            prefix[i][j] = tree + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
        }
    }

    while(m--){
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        int sm = prefix[y2][x2] - prefix[y2][x1-1] - prefix[y1-1][x2] + prefix[y1-1][x1-1];
        cout << sm << '\n';
    }
}
    