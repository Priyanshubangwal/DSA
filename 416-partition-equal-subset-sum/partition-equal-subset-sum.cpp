class Solution {
public:
    bool dpSum(int i,int sum,int n,vector<int>& nums,vector<vector<int>>& dp){
        if(i>n-1 || sum<0){
            return false;
        }

        if(sum==0){
            return true;
        }

        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        
        bool take=false,left=false;
        take= dpSum(i+1,sum-nums[i],n,nums,dp);
        left= dpSum(i+1,sum,n,nums,dp);
        
        return dp[i][sum]= take || left;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }

        if(sum%2!=0){
            return false;
        }

        sum=sum/2;

        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return dpSum(0,sum,n,nums,dp);

    }
};