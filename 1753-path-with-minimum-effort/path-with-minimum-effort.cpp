class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<vector<int>>distV={{1,0},{0,1},{-1,0},{0,-1}};
        int n= heights.size();
        int m= heights[0].size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        vector<vector<int>>distN(n,vector<int>(m,INT_MAX));
        distN[0][0]=0;

        while(!pq.empty()){
            int dist= pq.top().first;
            int x=    pq.top().second.first;
            int y=    pq.top().second.second;
            pq.pop();

            //if(x == n-1 && y == m-1) return dist;
            
            //if(dist > distN[x][y]) continue;

            for(auto &it: distV){
                int nx= x+ it[0];
                int ny= y+ it[1];

                if(nx>=0 && nx<n && ny>=0 && ny<m){
                    int newDist= max(dist, abs(heights[nx][ny] - heights[x][y]));
                    if(newDist< distN[nx][ny]){
                        distN[nx][ny]= newDist;
                        pq.push({newDist,{nx,ny}});
                    }                    
                }
            }
        }

        return distN[n-1][m-1];
    }
};