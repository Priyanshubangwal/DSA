class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int l=0,r=0;
        int n=s.length();
        int len=0;
        int maxL= 0;
        while(r<n){
            if(mp.contains(s[r])){
                if(mp[s[r]]>=l){
                    l= mp[s[r]]+1;
                }
            }
            len=r-l+1; 
            maxL= max(maxL,len);
            mp[s[r]]=r;
            r++;
        }

        return maxL;
    }
};