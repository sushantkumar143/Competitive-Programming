#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr(4);
    for(int i=0; i<4; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    int a = arr[3] - arr[0];
    int b = arr[3] - arr[1];
    int c = arr[3] - arr[2];

    cout << a << " " << b << " " << c;
}