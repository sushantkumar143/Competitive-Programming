#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    multiset<int> set;
    for(int i=0; i<n; i++){
        int data;
        cin >> data;
        set.insert(data);
    }

    for(auto it = set.begin(); it != set.end(); ++it) {
        cout << *it << " ";
    }
}
