class Solution {
public:
    int dpSum(int i,int j,int n,int m,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(i==n-1 && j==m-1){
            return dp[i][j]= grid[i][j];
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int down=INT_MAX,right=INT_MAX;

        if(i+1<n){
            down= grid[i][j]+ dpSum(i+1,j,n,m,grid,dp);
        }
        
        if(j+1<m){
            right= grid[i][j]+ dpSum(i,j+1,n,m,grid,dp);
        }
        
        return dp[i][j]= min(down,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return dpSum(0,0,n,m,grid,dp);
    }
};