#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s = "codeforces";
        char ch;
        cin >> ch;
        if (find(s.begin(), s.end(), ch) != s.end())
        {
            cout << "YES" << '\n';
        }

        else
            cout << "NO" << '\n';
    }

    return 0;
}
