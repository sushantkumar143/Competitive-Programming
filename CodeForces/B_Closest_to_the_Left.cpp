#include <bits/stdc++.h>
using namespace std;

int searchMax(vector<long long>& arr, int target){
    int left = 0;
    int right = arr.size()-1;
    int maxIndex = 0;

    while(left <= right){
        int mid = (left+right)/2;
        if(arr[mid] <= target){
            maxIndex = mid+1;
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
    return maxIndex;
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
        cout << searchMax(arr1, arr2[i]) << '\n';
    }
}