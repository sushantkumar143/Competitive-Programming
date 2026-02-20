#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;
        int high = 0;

        for(char& ch : s) {
            if(ch == '(') {
                low++;
                high++;
            }
            else if(ch == ')') {
                low--;
                high--;
            }
            else {
                low--;
                high++;
            }
            if(high < 0) return false;
            if(low < 0) low = 0;
        }

        return low==0;
    }
};

// class Solution {
// public:
//     bool checkValidString(string s) {
//         stack<int> open, star;

//         for (int i = 0; i < s.size(); ++i) {
//             if (s[i] == '(') {
//                 open.push(i);
//             } 
//             else if (s[i] == '*') {
//                 star.push(i);
//             } 
//             else if (s[i] == ')') {
//                 if (!open.empty()) {
//                     open.pop();
//                 } else if (!star.empty()) {
//                     star.pop();
//                 } else {
//                     return false;
//                 }
//             }
//         }

//         while (!open.empty() && !star.empty()) {
//             if (open.top() > star.top()) return false; 
//             open.pop();
//             star.pop();
//         }

//         return open.empty(); 
//     }
// };
