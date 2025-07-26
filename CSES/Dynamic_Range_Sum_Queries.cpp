#include <bits/stdc++.h>
using namespace std;

long long prefixSum(vector<long long>& fenwick, int ind){
    long long sum = 0;
    while(ind){
        sum += fenwick[ind];
        ind -= (ind & -ind);
    }
    return sum;
}

void update(vector<long long>& fenwick, int ind, long long val){
    while(ind < fenwick.size()){
        fenwick[ind] += val;
        ind += (ind & -ind);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<long long> arr(n);
    for(auto& x : arr) cin >> x;

    vector<long long> fenwick(n + 2, 0); 

    for(int i = 1; i <= n; i++){
        update(fenwick, i, arr[i - 1]);
    }

    while(q--){
        int ch;
        cin >> ch;

        if(ch == 1){
            int pos;
            long long val;
            cin >> pos >> val;
            long long delta = val - arr[pos - 1];
            arr[pos - 1] = val;
            update(fenwick, pos, delta);
        } else {
            int l, r;
            cin >> l >> r;
            cout << prefixSum(fenwick, r) - prefixSum(fenwick, l - 1) << '\n';
        }
    }
}
