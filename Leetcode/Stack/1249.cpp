#include<bits/stdc++.h>
using namespace std;

// VERY GOOD INTUTIVE QUESTION   --- MUST TRY ---


    // APPROACH - 1
    
    class Solution {
        public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        int n = s.length();
        
        for(int i=0; i<n; i++) {
            if(s[i] == '(') {
                st.push(i);
            }
            else if(s[i] == ')') {
                if(!st.empty()) {
                    st.pop();
                }
                else {
                    s[i] = '*';
                }
            }
        }
        
        while(!st.empty()) {
            s[st.top()] = '*';
            st.pop();
        }

        string ans = "";
        for(char ch : s) {
            if(ch != '*') ans += ch;
        }

        return ans;
    }
};  


    // APPROACH - 2

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> st;
        int n = s.length();
        int open = 0;
        int close = 0;

        for(int i=0; i<n; i++) {
            if(s[i] >= 'a' && s[i] <= 'z') st.push(s[i]);
            else if(s[i] == '(') {
                st.push('(');
                open++;
            }
            else if(s[i] == ')' && open > close) {
                st.push(s[i]);
                close++;
            }
        }

        string ans = "";
        int temp = close;
        while(!st.empty()) {
            char ch = st.top();
            st.pop();
            
            if(ch >= 'a' && ch <= 'z') ans += ch;
            else if(ch == ')') {
                ans += ch;
            }
            else {
                if(open == close) ans += ch;
                else open--;
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};