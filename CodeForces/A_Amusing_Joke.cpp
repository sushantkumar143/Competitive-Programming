#include<bits/stdc++.h>
using namespace std;

int main(){
    string f, l, p;
    cin >> f >> l >> p;

    char arr1[26] = {0};
    char arr2[26] = {0};

    for(char ch : f){
        arr1[ch-'A']++;
    }
    for(char ch : l){
        arr1[ch-'A']++;
    }
    for(char ch : p){
        arr2[ch-'A']++;
    }

    for(int i=0; i<26; i++){
        if(arr1[i] != arr2[i]){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
