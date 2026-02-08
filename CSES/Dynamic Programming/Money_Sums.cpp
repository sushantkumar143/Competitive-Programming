#include <bits/stdc++.h>
using namespace std;

void fun(int idx, int sm, vector<int>& arr, set<int>& st) {
    if(idx < 0) return;

    fun(idx-1, sm, arr, st);
    sm += arr[idx];
    st.insert(sm);
    fun(idx-1, sm, arr, st);
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int& x : arr) cin >> x;

    set<int> st;
    fun(n-1, 0, arr, st);

    vector<int> ans(st.begin(), st.end());

    cout << ans.size() << '\n';    
    for(int x : ans) cout << x << " ";
}