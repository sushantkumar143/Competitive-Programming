#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countOfSubstrings(string word, int k) {
        int a=0,e=0,i_=0,o=0,u=0;
        int consonant = 0;
        int left = 0;
        long long ans = 0;
        int n = word.size();

        for(int right = 0; right < n; right++) {
            char ch = word[right];

            if(ch=='a') a++;
            else if(ch=='e') e++;
            else if(ch=='i') i_++;
            else if(ch=='o') o++;
            else if(ch=='u') u++;
            else consonant++;

            while(consonant > k) {
                char c = word[left++];
                if(c=='a') a--;
                else if(c=='e') e--;
                else if(c=='i') i_--;
                else if(c=='o') o--;
                else if(c=='u') u--;
                else consonant--;
            }

            int tempLeft = left;
            int ta=a, te=e, ti=i_, to=o, tu=u;
            int tc=consonant;

            while(tempLeft <= right && tc==k && ta>0 && te>0 && ti>0 && to>0 && tu>0) {
                ans++;
                char c = word[tempLeft++];
                if(c=='a') ta--;
                else if(c=='e') te--;
                else if(c=='i') ti--;
                else if(c=='o') to--;
                else if(c=='u') tu--;
                else tc--;
            }
        }

        return ans;
    }
};
