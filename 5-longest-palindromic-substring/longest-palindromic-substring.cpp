class Solution {
public:
    bool checkPal(int i,int j,string &s){
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
    string longestPalindrome(string s) {
        int n= s.length();
        int l=0;
        int maxL=0;
        int p=0;
        int q=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(checkPal(i,j,s)){
                   l=j-i+1;
                   if(l>maxL){
                    p= i;
                    q= j;
                   }
                   maxL= max(maxL,l);
                }
            }
        }
        
        string res="";
        for(int i=p;i<=q;i++){
            res+=s[i];
        }

        return res;
    }
};