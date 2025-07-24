#include <bits/stdc++.h>
using namespace std;

void helper(vector<vector<char>> arr, int n, int m){
    int hash = 0;
    int row, col;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] == '#'){
                hash++;
                row = i;
                col = j;
            }
        }
    }
    if(hash == 1){
        cout << row+1 << " " << col+1 << '\n';
        return;
    }

    hash = hash/2 + 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] == '#'){
                hash--;
            }
            if(!hash){
                cout << i+1 << " " << j+1 << '\n';
            }
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n,m;
        cin >> n >> m;
        vector<vector<char>> arr(n, vector<char>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> arr[i][j];
            }
        }

        helper(arr, n, m);
    }
}