#include<bits/stdc++.h>
using namespace std;

// THERE ARE 2 APPROACH FOR THIS QUESTION
// 1. USE MERGE SORT TO COUNT
// 2. USE ordered_set<> THAT STORE ELEMENTS IN SORTED ORDER AND WE CAN FIND LOWER BOUND OF THAT ELEMENT

class Solution {
  public:
    int merge(vector<int> &arr, int l, int mid, int r) {
        int i = l;
        int j = mid+1;
        vector<int> merged;
        int inversions = 0;
        
        while(i<=mid && j<=r) {
            if(arr[i] <= arr[j]) {
                merged.push_back(arr[i]);
                i++;
            }
            else {
                inversions += mid - i + 1;
                merged.push_back(arr[j]);
                j++;
            }
        }
        while(i<=mid) merged.push_back(arr[i++]);
        while(j<=r) merged.push_back(arr[j++]);
        
        for(int i=l; i<=r; i++) {
            arr[i] = merged[i-l];
        }
        
        return inversions;
    }
  
    int countInversions(vector<int> &arr, int l, int r) {
        if(l >= r) return 0;
        
        int inversions = 0;
        int mid = l + (r-l)/2;
        
        inversions += countInversions(arr, l, mid);
        inversions += countInversions(arr, mid+1, r);
        inversions += merge(arr, l, mid, r);
        
        return inversions;
    }
  
    int inversionCount(vector<int> &arr) {
        // Code Here
        return countInversions(arr, 0, arr.size()-1);
    }
};