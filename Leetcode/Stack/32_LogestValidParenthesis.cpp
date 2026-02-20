#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int longestValidParentheses(string s) {
//         stack<int> st;
//         st.push(-1);
//         int max_len = 0;

//         for (int i = 0; i < s.length(); i++) {
//             if (s[i] == '(') {
//                 st.push(i);
//             } 
//             else {
//                 st.pop();
//                 if (st.empty()) {
//                     st.push(i);
//                 } 
//                 else {
//                     max_len = max(max_len, i - st.top());
//                 }
//             }
//         }
//         return max_len;        
//     }
// };


class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0;
        int maxLen = 0;

        // Left to Right
        for(char ch : s) {
            if(ch == '(') left++;
            else right++;

            if(left == right) {
                maxLen = max(maxLen, 2 * right);
            }
            else if(right > left) {
                left = right = 0;
            }
        }

        left = right = 0;

        // Right to Left
        for(int i = s.length() - 1; i >= 0; i--) {
            if(s[i] == '(') left++;
            else right++;

            if(left == right) {
                maxLen = max(maxLen, 2 * left);
            }
            else if(left > right) {
                left = right = 0;
            }
        }

        return maxLen;
    }
};