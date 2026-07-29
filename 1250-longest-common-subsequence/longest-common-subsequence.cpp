class Solution {
public:
    int dpSeq(int i,int j,int n,int m,string & text1, string & text2,vector<vector<int>>& dp){
        if(i>=n || j>=m){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int take=INT_MIN,left=0;
        if(i<n && j<m && text1[i]==text2[j]){
            take= 1+ dpSeq(i+1,j+1,n,m,text1,text2,dp);
        }else if(i<n && text1[i]!=text2[j]){
            left= max(dpSeq(i+1,j,n,m,text1,text2,dp), dpSeq(i,j+1,n,m,text1,text2,dp));
        }

        return dp[i][j]= max(take,left);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n= text1.size();
        int m= text2.size();

        vector<vector<int>>dp(n,vector<int>(m,-1));
        return dpSeq(0,0,n,m,text1,text2,dp);
    }
};