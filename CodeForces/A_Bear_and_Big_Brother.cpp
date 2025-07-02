#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, m;
    cin >> n >> m;

    int cnt = 0;
    while(n <= m){
        n *= 3;
        m *= 2;
        cnt++;
    }
    cout << cnt;
}