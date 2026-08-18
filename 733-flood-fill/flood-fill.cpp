class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>dirs={{0,-1},{-1,0},{0,1},{1,0}};
        int n= image.size();
        int m= image[0].size();
        if(image[sr][sc]==color){
            return image;
        }
        int orgclr= image[sr][sc];
        image[sr][sc]= color;
        queue<pair<int,int>>q;
        q.push({sr,sc});
        while(!q.empty()){
            int x= q.front().first;
            int y= q.front().second;
            q.pop();

            for(auto &v: dirs){
                int dx= x+ v[0];
                int dy= y+ v[1];

                if(dx>=0 && dx<n && dy>=0 && dy<m && image[dx][dy]==orgclr){
                    image[dx][dy]= color;
                    q.push({dx,dy});
                }
            }
        }

        return image;
    }
};