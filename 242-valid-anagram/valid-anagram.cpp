class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>s1(26,0);
        vector<int>t1(26,0);
        for(char c: s){
            s1[c-'a']++;
        }

        for(char c: t){
            t1[c-'a']++;
        }

        if(s1==t1){
            return true;
        }

        return false;
    }
};