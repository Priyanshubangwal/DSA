class Solution {
public:
    void calldp(int i,int j, int n, int m, vector<vector<char>>& grid, vector<vector<int>>& dir,vector<vector<int>>& visited){
        if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j]=='0' || visited[i][j] == 1){
            return ;
        }
        visited[i][j]= 1;
        for(auto &v: dir){
            int dx= i+ v[0];
            int dy= j+ v[1];

            if(dx>=0 && dy>=0 && dx<n && dy<m && grid[dx][dy]=='1'){
                calldp(dx,dy,n,m,grid,dir,visited);
            }
        }
        
        return;
    }

    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>>dir={{1,0},{0,1},{0,-1},{-1,0}};
        int n= grid.size();
        int m= grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,-1));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && visited[i][j]==-1){
                    calldp(i,j,n,m,grid,dir,visited);
                    count++;
                }
            }
        }

        return count;
    }
};