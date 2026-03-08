#include<bits/stdc++.h>
using namespace std;

int findPivot(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j < high; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i;
}

void quickSort(vector<int>& arr, int left, int right) {
    if(left > right) return;

    int pivot = findPivot(arr, left, right);
    quickSort(arr, left, pivot);
    quickSort(arr, pivot+1, right);
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int& x : arr) cin >> x;

    quickSort(arr, 0, n-1);
    for(int x : arr) cout << x << " ";
    cout << endl;
}