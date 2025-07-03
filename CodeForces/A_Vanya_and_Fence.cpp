#include <iostream>
#include <string>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int total = 0;
    int data;
    for(int i=0; i<n; i++){
        cin >> data;
        if(data>k) total += 2;
        else total += 1;
    }

    cout << total;
}
