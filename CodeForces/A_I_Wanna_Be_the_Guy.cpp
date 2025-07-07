#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    set<int> st;

    int p;
    cin >> p;

    for(int i=0; i<p; i++){
        int data;
        cin >> data;
        st.insert(data);
    }

    int q;
    cin >> q;

    for(int i=0; i<q; i++){
        int data;
        cin >> data;
        st.insert(data);
    }

    if(st.size() == n) cout << "I become the guy.";
    else cout << "Oh, my keyboard!";
}
