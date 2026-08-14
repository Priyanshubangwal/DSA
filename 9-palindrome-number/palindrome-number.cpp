class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        
        int act= x;
        long long rev=0;
        while(x!=0){
            long long mod= x%10;
            rev= (rev*10)+ mod;
            x= x/10;
        }

        if(act==rev){
            return true;
        }

        return false;
    }
};