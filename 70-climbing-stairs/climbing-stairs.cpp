class Solution {
public:
    int callDp(int n,vector<int>& dp){
        if(n<0){
            return 0;
        }
        if(n==0){
            return 1;
        }

        if(dp[n]!=-1){
            return dp[n];
        }

        int takeOne, takeTwo;
        
        takeOne= callDp(n-1,dp);
        takeTwo= callDp(n-2,dp);
        
        return dp[n]= takeOne+takeTwo;
    }
    int climbStairs(int n){
        vector<int>dp(n+1,-1);
        int ans= callDp(n,dp);
        return ans;
    }
};