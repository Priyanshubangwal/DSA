class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses);
        queue<int>q;

        for(auto &v: prerequisites){
            int a= v[0];
            int b= v[1];

            adj[b].push_back(a);
        }

        for(int i=0;i<numCourses;i++){
            for(int &v: adj[i]){
                indegree[v]++;
            }
        }

        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        vector<int>result;
        while(!q.empty()){
            int u= q.front();
            q.pop();
            result.push_back(u);

            for(int &v: adj[u]){
                indegree[v]--;

                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }

        if(result.size()==numCourses){
            return true;
        }

        return false;
    }
};