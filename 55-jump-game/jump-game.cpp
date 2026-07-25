class Solution {
public:
    bool solveDp(int n,int jump ,vector<int>& nums, vector<int>& dp){
        if(jump>=n-1){
            return true;
        }

        if(dp[jump]!=-1){
            return dp[jump];
        }

        int i=nums[jump];
        if(i==0){
            return dp[jump]= false;
        }

        for(int j=i;j>0;j--){
            if(solveDp(n,jump+j,nums,dp)){
                return dp[jump]= true;
            };
        }
        
        return dp[jump]= false;
    }
    bool canJump(vector<int>& nums) {
        int n= nums.size();
        vector<int>dp(n,-1);
        return solveDp(n,0,nums,dp);
    }
};