#include <bits/stdc++.h>
using namespace std;

int searchMin(vector<long long>& arr, int target){
    int left = 0;
    int right = arr.size()-1;
    int minIndex = 0;

    while(left <= right){
        int mid = (left+right)/2;
        if(arr[mid] >= target){
            minIndex = mid+1;
            right = mid-1;
        }
        else{
            left = mid+1;
        }
    }
    if(!minIndex) return arr.size()+1;
    return minIndex;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<long long> arr1(n);
    vector<long long> arr2(m);

    for(int i=0; i<n; i++){
        cin >> arr1[i];
    }
    for(int i=0; i<m; i++){
        cin >> arr2[i];
    }

    for(int i=0; i<m; i++){
        cout << searchMin(arr1, arr2[i]) << '\n';
    }
}