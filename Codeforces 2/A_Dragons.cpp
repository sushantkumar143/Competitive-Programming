#include <bits/stdc++.h>
using namespace std;

int main() {
    int s, n;
    cin >> s >> n;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    while(n--) {
        int d, b;
        cin >> d >> b;

        pq.push({d, b});
        if(s >= pq.top().first) {
            s += pq.top().second;
            pq.pop();
        }
    }

    while (!pq.empty())
    {
        int st = pq.top().first;
        int bo = pq.top().second;

        if(bo > s) {
            cout << "NO";
            return 0;
        }

        s += bo;
        pq.pop();
    }

    if(pq.empty()) cout << "YES";
    else cout << "NO";
    
}