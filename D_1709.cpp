#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr1;
        vector<int> arr2;

        for(int i=0; i<n; i++) cin >> arr1[i];
        for(int i=0; i<n; i++) cin >> arr2[i];

        vector<pair<int, int>> oprt;
        
        for(int i=0; i<n-1; i++){
            for(int j=0; j<n-i-1; j++){
                if(arr1[j]>arr1[j+1]){
                    swap(arr1[j], arr1[j+1]);
                    oprt.push_back({1, j+1});
                }
            }
        }
        
        for(int i=0; i<n-1; i++){
            for(int j=0; j<n-i-1; j++){
                if(arr2[j]>arr2[j+1]){
                    swap(arr2[j], arr2[j+1]);
                    oprt.push_back({2, j+1});
                }
            }
        }
        
        for(int i=0; i<n; i++){
            if(arr1[i] > arr2[i]){
                swap(arr1[i], arr2[i]);
                oprt.push_back({3, i+1});
            }
        }

        cout << oprt.size() << '\n';
        for (auto i : oprt) {
            cout << i.first << " " << i.second << '\n';
        }
    }
}