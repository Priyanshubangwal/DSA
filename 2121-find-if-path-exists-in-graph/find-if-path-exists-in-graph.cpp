class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        queue<int> q;
        q.push(source);
        vector<bool> visit(n,false);
        visit[source] = true;

        while(!q.empty()){
            int d = q.front();
            q.pop();

            if(d == destination) return true;

            for(int nei : adj[d]){
                if(!visit[nei]){
                    q.push(nei);
                    visit[nei] = true;
                }
            }
        }

        return false;
    }
};