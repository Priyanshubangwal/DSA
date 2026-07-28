class Solution {
public:
    int coinDp(int i, int n, vector<int>&coins, int amount,vector<vector<int>>& dp){
        if(amount==0){
            return 0;
        }

        if(i==n){
            return 1e9;
        }
        
        if(dp[i][amount]!=-1){
            return dp[i][amount];
        }
        int take=1e9,left=0;
        if(coins[i]<=amount){
        take= 1+ coinDp(i,n,coins,amount-coins[i],dp);
        }
        left= coinDp(i+1,n,coins,amount,dp);


        return dp[i][amount]= min(take,left);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int ans= coinDp(0,n,coins,amount,dp);
        if(ans>=1e9){
            return -1;
        }

        return ans;
    }
};