class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto &e: times){
            int u= e[0];
            int v= e[1];
            int w= e[2];

            adj[u].push_back({v,w});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>distN(n+1,INT_MAX);
        distN[k]=0;
        pq.push({0,k});

        while(!pq.empty()){
            int dist= pq.top().first;
            int node= pq.top().second;
            pq.pop();

            for(auto &it : adj[node]){
                int distNode=  it.first;
                int weightNode=it.second;

                if(distN[distNode]> distN[node]+ weightNode){
                    distN[distNode]= distN[node]+ weightNode;
                    pq.push({distN[distNode],distNode});
                }
            }
        }
        
        int maxD=INT_MIN;
        for(int i=1;i<=n;i++){
            if(distN[i]==INT_MAX){
                return -1;
            }
            maxD= max(maxD, distN[i]);
        }

        return maxD;
    }
};