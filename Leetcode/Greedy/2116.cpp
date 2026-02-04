#include<bits/stdc++.h>
using namespace std;

// VERY GOOD INTUTIVE QUESTION   --- MUST TRY ---

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n =s.length();
        if(n%2) return false;
        int minOpen = 0;
        int maxOpen = 0;

        for(int i=0; i<n; i++) {
            if(locked[i] == '1') {
                if(s[i] == '(') {
                    minOpen++;
                    maxOpen++;
                }
                else {
                    minOpen--;
                    maxOpen--;
                }
            }
            else {
                minOpen--;
                maxOpen++;
            }

            if(maxOpen < 0) return false;
            minOpen = max(minOpen, 0);
        }

        return minOpen == 0;
    }
};