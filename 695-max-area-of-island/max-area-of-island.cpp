class Solution {
public:
    int findNeigh(int i, int j, int n, int m, vector<vector<int>>& grid,vector<vector<int>>& dir, vector<vector<bool>> & visited){
        visited[i][j]= true;
        int area=1;

        for(auto &d : dir){
            int nx = i + d[0];
            int ny = j + d[1];

            if(nx >= 0 && nx < n && ny >= 0 && ny < m &&
               !visited[nx][ny] && grid[nx][ny] == 1){
                area += findNeigh(nx, ny, n, m, grid, dir, visited);
            }
        }
        return area; 
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<int>>dir={{1,0},{0,1},{0,-1},{-1,0}};
        int n= grid.size();
        int m= grid[0].size();
        int maxArea=0;

        vector<vector<bool>>visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==false && grid[i][j]==1){
                    
                    maxArea= max(maxArea,findNeigh(i,j,n,m,grid,dir,visited));
                }
            }
        }
        
        return maxArea;
    }
};