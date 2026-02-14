class Solution {
  public:
    
    int expand(string &s, int l, int r) {
        int n = s.length();
        while(l >= 0 && r < n && s[l] == s[r]) {
            l--;
            r++;
        }
        return r - l - 1;   // length of palindrome
    }
    
    string longestPalindrome(string &s) {
        int n = s.length();
        if(n == 0) return "";
        
        int start = 0, maxLen = 1;
        
        for(int i = 0; i < n; i++) {
            // odd length palindrome
            int len1 = expand(s, i, i);
            // even length palindrome
            int len2 = expand(s, i, i + 1);
            
            int len = max(len1, len2);
            
            if(len > maxLen) {
                maxLen = len;
                start = i - (len - 1) / 2;
            }
        }
        
        return s.substr(start, maxLen);
    }
};