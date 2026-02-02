class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> used(26, false);
        vector<int> freq(26, 0);
        
        for(char ch : s) {
            freq[ch - 'a']++;
        }

        string st = "";

        for(char ch : s) {
            freq[ch - 'a']--;
            if(used[ch - 'a']) continue;

            while(!st.empty() && st.back() > ch && freq[st.back() - 'a'] > 0) {
                used[st.back() - 'a'] = false;
                st.pop_back();
            }

            st.push_back(ch);
            used[ch - 'a'] = true;
        }

        return st;
    }
};