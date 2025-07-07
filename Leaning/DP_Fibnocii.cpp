#include <bits/stdc++.h>
using namespace std;

int fib(int n, int arr[]) {
    if (n <= 1) return n;

    if (arr[n] != -1) return arr[n];

    arr[n] = fib(n - 1, arr) + fib(n - 2, arr);
    // cout<<n<<" ";
    return arr[n];
}

int main() {
    int n;
    cin >> n;

    int arr[n + 1];
    memset(arr, -1, sizeof(arr));

    cout << fib(n, arr);
}
