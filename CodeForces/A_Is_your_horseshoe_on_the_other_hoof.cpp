#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> colors;
    int s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;

    colors.insert(s1);
    colors.insert(s2);
    colors.insert(s3);
    colors.insert(s4);

    cout << 4 - colors.size() << endl;
    return 0;
}
