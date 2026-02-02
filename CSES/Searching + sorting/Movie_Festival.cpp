#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr.begin(), arr.end(), comp);

    int last = arr[0].second;
    int cnt = 1;

    for(int i=1; i<n; i++) {
        if(arr[i].first >= last) {
            last = arr[i].second;
            cnt++;
        }
    }

    cout << cnt;
    return 0;
}