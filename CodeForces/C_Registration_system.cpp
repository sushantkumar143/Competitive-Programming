#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    unordered_map<string, int> map;

    while(t--){
        string s;
        cin >> s;

        if(map.find(s) != map.end()){
            cout << s + to_string(map[s]) << '\n';
            map[s]++;
        }
        else{
            cout << "OK" << '\n';
            map[s]++;
        }
    }
}