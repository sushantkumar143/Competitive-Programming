#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        deque<int> p(n);
        for(int i = 0; i < n; i++){
            cin >> p[i];
        }
        string res;
        vector<int> q;
        q.reserve(n);

        auto bad5 = [&](int v){
            int m = q.size();
            if(m < 4) return false;
            int a = q[m-4], b = q[m-3], c = q[m-2], d = q[m-1], e = v;
            return (a < b && b < c && c < d && d < e)
                || (a > b && b > c && c > d && d > e);
        };

        for(int i = 0; i < n; i++){
            int l = p.front(), r = p.back();
            if(!bad5(l)){
                res += 'L';
                q.push_back(l);
                p.pop_front();
            } else {
                res += 'R';
                q.push_back(r);
                p.pop_back();
            }
        }

        cout << res << "\n";
    }
    return 0;
}
