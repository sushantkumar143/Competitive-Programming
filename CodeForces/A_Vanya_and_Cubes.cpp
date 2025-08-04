#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int height = 0;
    int cubes_used = 0;
    int level_cubes = 0;

    while (true) {
        height++;
        level_cubes += height;
        cubes_used += level_cubes;

        if (cubes_used > n) break;
    }

    cout << height - 1 << endl;
    return 0;
}
