#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n); 
    for (int i = 0; i < n; i++) cin >> arr[i];

    int s = 0, ne = 0;
    int left = 0, right = n - 1;
    bool turn = true;

    while (left <= right) {
        int pick;
        if (arr[left] > arr[right]) {
            pick = arr[left];
            left++;
        } else {
            pick = arr[right];
            right--;
        }

        if (turn)
            s += pick;
        else
            ne += pick;

        turn = !turn;
    }

    cout << s << " " << ne << endl;
    return 0;
}
