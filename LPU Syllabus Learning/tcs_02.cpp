#include<bits/stdc++.h>
using namespace std;
int n;

int fun(int idx, vector<int>& risk, vector<int>& profit, int r, vector<pair<int, int>>& pair) {
    if(idx >= n) return 0;

    int notTake = fun(idx+1, risk, profit, r);
    if()
    int take = profit[idx] + fun(idx+2, risk, profit, r-risk[idx]);

    return max(take, notTake);
}

int maxProfit(vector<int>& risk, vector<int>& profit, int r, vector<pair<int, int>>& pair) {
    return fun(0, risk, profit, r, pair);
}

int main() {
    int r;
    cin >> n >> r;

    vector<int> risk(n), profit(n);
    
    for(int& x : profit) cin >> x;
    for(int& x : risk) cin >> x;

    int pair;
    cin >> pair;

    vector<pair<int, int>> pair;
    for(int i=0; i<pair; i++) {
        int a,b;
        cin >> a >> b;
        pair.first = a;
        pair.second = b;
    }

    cout << maxProfit(risk, profit, r, pair);
}