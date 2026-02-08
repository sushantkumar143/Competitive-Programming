#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        int n = s.length();
        stack<int> num;
        stack<string> words;
        string currStr = "";
        int k = 0;

        for(char ch: s){
            if(isdigit(ch)){
                k = k*10 + (ch-'0');
            }
            else if(ch == '['){
                num.push(k);
                k = 0;
                words.push(currStr);
                currStr = "";
            }
            else if(ch == ']'){
                string expand = "";
                int t = num.top();
                num.pop();
                for(int i=0; i<t; i++){
                    expand += currStr;
                }
                currStr = words.top() + expand;
                words.pop();
            }
            else{
                currStr += ch;
            }
        }
        return currStr;
    }
};