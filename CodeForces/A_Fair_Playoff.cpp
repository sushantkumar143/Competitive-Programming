#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int t;
    cin >> t;

    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int semi1_winner = max(a, b);
        int semi2_winner = max(c, d);

        vector<int> players = {a, b, c, d};
        sort(players.begin(), players.end());

        int best = players[3];
        int second_best = players[2];

        if ((best == semi1_winner && second_best == semi2_winner) ||
            (best == semi2_winner && second_best == semi1_winner)) {
            cout << "YES\n";
        } 
        else {
            cout << "NO\n";
        }
    }
}
