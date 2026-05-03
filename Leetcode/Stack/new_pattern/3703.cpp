#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeSubstring(string s, int k) {
        vector<pair<char,int>> st;

        for(char ch : s) {
            if(!st.empty() && st.back().first == ch) {
                st.back().second++;
            } else {
                st.push_back({ch, 1});
            }

            if(st.size() >= 2) {
                auto top1 = st.back(); st.pop_back(); // ')'
                auto top2 = st.back(); st.pop_back(); // '('

                if(top1.first == ')' && top2.first == '(' &&
                   top1.second >= k && top2.second >= k) {

                    top1.second -= k;
                    top2.second -= k;

                    if(top2.second > 0) st.push_back(top2);
                    if(top1.second > 0) st.push_back(top1);
                }
                else {
                    st.push_back(top2);
                    st.push_back(top1);
                }
            }
        }

        string res;
        for(auto &[ch, cnt] : st) {
            res.append(cnt, ch);
        }

        return res;
    }
};


// class Solution {
// public:
//     string removeSubstring(string s, int k) {
//         stack<pair<char,int>> st;
        
//         for(char ch : s) {
//             if(!st.empty() && st.top().first == ch) st.top().second++;
//             else st.push({ch, 1});

//             if(st.size() >= 2) {
//                 auto top1 = st.top();
//                 st.pop();
//                 auto top2 = st.top();
//                 st.pop();
                
//                 if(top1.first==')' && top2.first=='(' && top1.second>=k && top2.second>=k) {
//                     top1.second -= k;
//                     top2.second -= k;
//                     if(top2.second > 0) st.push(top2);
//                     if(top1.second > 0) st.push(top1);
//                 }
//                 else {
//                     st.push(top2);
//                     st.push(top1);
//                 }
//             }
//         }

//         string res = "";
//         while(!st.empty()) {
//             auto [ch, cnt] = st.top();
//             st.pop();
//             res = string(cnt, ch) + res;
//         }

//         return res;
//     }
// };