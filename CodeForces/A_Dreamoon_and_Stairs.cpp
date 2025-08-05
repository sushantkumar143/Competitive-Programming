#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int min_moves = (n + 1) / 2;
    int answer = -1;

    for (int moves = min_moves; moves <= n; ++moves) {
        if (moves % m == 0) {
            answer = moves;
            break;
        }
    }

    cout << answer << endl;
    return 0;
}
