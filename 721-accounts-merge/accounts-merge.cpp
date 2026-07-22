class DSU{
    vector<int>parent;
    vector<int>rank;
    public:
    DSU(int n){
        parent.resize(n);
        rank.resize(n,0);

        for(int i=0;i<parent.size();i++){
            parent[i]=i;
        }
    }

    int find(int u){
        if(parent[u]==u){
            return u;
        }

        return parent[u]= find(parent[u]);
    }

    void unionRank(int u,int v){
        int up= find(u);
        int vp= find(v);

        if(vp==up){
            return;
        }

        if(rank[up]<rank[vp]){
            parent[up]=vp;
        }else if(rank[vp]<rank[up]){
            parent[vp]=up;
        }else{
            parent[vp]=up;
            rank[up]++;
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n= accounts.size();
        DSU dsu(n);

        unordered_map<string,int>mailNode;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail= accounts[i][j];

                if(mailNode.find(mail)==mailNode.end()){
                    mailNode[mail]=i;
                }else{
                    dsu.unionRank(i,mailNode[mail]);
                }
            }
        }

        vector<string>mergeMail[n];
        for(auto &it :mailNode){
            string mail= it.first;
            int node= dsu.find(it.second);

            mergeMail[node].push_back(mail);
        }

        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            if(mergeMail[i].size()==0) continue;

            sort(mergeMail[i].begin(),mergeMail[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);

            for(auto &it: mergeMail[i]){
                temp.push_back(it);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};