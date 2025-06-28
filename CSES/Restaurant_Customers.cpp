#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<pair<int,int>> events;

    for(int i=0; i<n; i++){
        int a,b;
        cin >> a >> b;

        events.push_back({a,1});
        events.push_back({b,-1});
    }

    sort(events.begin(), events.end());

    int maxCustomer = 0;
    int temp = 0;

    for(auto t : events){
        // if(t.second == 1) temp++;
        // else temp--;
        temp += t.second;
        maxCustomer = max(maxCustomer, temp);
    }
    cout << maxCustomer;
}