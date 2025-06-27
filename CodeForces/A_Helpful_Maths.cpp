#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    int n = s.length();
    vector<int> arr;

    for(int i=0; i<n; i+=2){
        arr.push_back(s[i]-'0');
    }

    int low = 0, mid = 0, high = arr.size() - 1;

    while (mid <= high) {
        if (arr[mid] == 1) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 2) {
            mid++;
        }
        else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }

    string ans = "";
    for(int i=0; i<arr.size(); i++){
        ans += to_string(arr[i]);
        if(i<arr.size()-1) ans += '+';
    }
    cout<<ans;
}