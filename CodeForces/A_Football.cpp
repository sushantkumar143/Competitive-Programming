#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<string, int> score;
    string team;

    while (n--) {
        cin >> team;
        score[team]++;
    }

    string winner = "";
    int maxGoals = 0;

    for (auto &entry : score) {
        if (entry.second > maxGoals) {
            maxGoals = entry.second;
            winner = entry.first;
        }
    }

    cout << winner << endl;
    return 0;
}
