#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        int n = a.size();
        int m = b.size();
        int i = 0, j = 0;
        int last_element = 0;

        while (i < n && j < m) {
            if (a[i] < b[j]) {
                last_element = a[i];
                i++;
            } 
            else {
                last_element = b[j];
                j++;
            }
            k--;
            if (k == 0) return last_element;
        }

        while (i < n) {
            last_element = a[i];
            i++;
            k--;
            if (k == 0) return last_element;
        }

        while (j < m) {
            last_element = b[j];
            j++;
            k--;
            if (k == 0) return last_element;
        }

        return last_element;
    }
};