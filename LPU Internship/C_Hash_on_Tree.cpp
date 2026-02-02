#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll MOD = 998244353;

int n, q;
vector<int> parent;
vector<vector<int>> children;
vector<ll> A;
vector<ll> f;

vector<ll> prod_nonzero; 
vector<int> zero_count;

ll power(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

ll mod_inverse(ll n) {
    return power(n, MOD - 2);
}

ll compute_f_value_fast(int n) {
    if (children[n].empty()) {
        return A[n] % MOD;
    } else {
        if (zero_count[n] > 0) {
            return A[n] % MOD;
        } else {
            return (A[n] + prod_nonzero[n]) % MOD;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;

    parent.resize(n + 1, 0);
    children.resize(n + 1);
    A.resize(n + 1);
    f.resize(n + 1);
    
    prod_nonzero.resize(n + 1, 1);
    zero_count.resize(n + 1, 0);

    for (int i = 2; i <= n; i++) {
        cin >> parent[i];
        children[parent[i]].push_back(i);
    }

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    for (int i = n; i >= 1; i--) {
        if (children[i].empty()) {
            f[i] = A[i] % MOD;
        } else {
            for (int child : children[i]) {
                if (f[child] == 0) {
                    zero_count[i]++;
                } else {
                    prod_nonzero[i] = (prod_nonzero[i] * f[child]) % MOD;
                }
            }
            f[i] = compute_f_value_fast(i);
        }
    }

    for (int k = 0; k < q; k++) {
        int v;
        ll x;
        cin >> v >> x;

        A[v] = x;

        int curr = v;
        while (curr != 0) {
            ll old_f = f[curr];
            ll new_f = compute_f_value_fast(curr);

            if (old_f == new_f) {
                break;
            }
            
            f[curr] = new_f;
            int p = parent[curr];
            if (p == 0) {
                break;
            }

            ll old_val = old_f;
            ll new_val = new_f;

            
            if (old_val == 0 && new_val == 0) {
            } 
            else if (old_val != 0 && new_val != 0) {
                prod_nonzero[p] = (prod_nonzero[p] * new_val) % MOD;
                prod_nonzero[p] = (prod_nonzero[p] * mod_inverse(old_val)) % MOD;
            } 
            else if (old_val == 0 && new_val != 0) {
                zero_count[p]--;
                prod_nonzero[p] = (prod_nonzero[p] * new_val) % MOD;
            } else if (old_val != 0 && new_val == 0) {
                zero_count[p]++;
                prod_nonzero[p] = (prod_nonzero[p] * mod_inverse(old_val)) % MOD;
            }
            
            curr = p; 
        }

        cout << f[1] << "\n";
    }

    return 0;
}