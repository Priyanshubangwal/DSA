class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n= rooms.size();
        vector<vector<int>>adj(n);

        for(int i=0;i<n;i++){
            for(int key: rooms[i]){
                adj[i].push_back(key);
            }
        }

        queue<int>q;
        q.push(0);

        vector<int>visited(n,false);
        visited[0]=true;

        while(!q.empty()){
            int d= q.front();
            q.pop();

            for(int neig: adj[d]){
                if(visited[neig]==false){
                    q.push(neig);
                    visited[neig]=true;
                }
            }
        }

        for(int i=0;i<visited.size();i++){
            if(visited[i]==false){
                return false;
            }
        }

        return true;
    }
};