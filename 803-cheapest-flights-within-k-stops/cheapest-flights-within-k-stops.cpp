class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto &it : flights){
            int u= it[0];
            int v= it[1];
            int w= it[2];

            adj[u].push_back({v,w});
        }
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        vector<vector<int>> distN(n, vector<int>(k+2, INT_MAX));
        distN[src][0] = 0;
        pq.push({0,src,0});

        while(!pq.empty()){
            auto[dist,node,steps]=pq.top();
            pq.pop();

            for(auto &it: adj[node]){
                int distNode=  it.first;
                int weightNode=it.second;
                

                if(steps<=k && distN[distNode][steps+1]>dist+ weightNode){
                    distN[distNode][steps+1]= dist+ weightNode;
                    pq.push({distN[distNode][steps+1],distNode,steps+1});
                }
            }
        }
        
        int ans = INT_MAX;
        for(int i=0;i<=k+1;i++){
            ans = min(ans, distN[dst][i]);
        }
        return ans == INT_MAX ? -1 : ans;

    }
};