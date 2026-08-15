class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long ans=0;
        int n= s.length();
        for(int i=0;i<n;i++){
            if(s[i]==c){
                ans++;
            }
        }
        if(ans==0 || ans==1){
            return ans; 
        }

        long long res= ans;
        while(ans>1){
            ans--;
            res+= ans;
        }

        return res;
    }
};