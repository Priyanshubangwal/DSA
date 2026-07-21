class DSU{
    vector<int>rank;
    vector<int>parent;
public:
    DSU(int n){
        rank.resize(n,0);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }

    int find(int i){
        if(parent[i]==i){
            return i;
        }

        return parent[i]= find(parent[i]);
    }

    bool unionFind(int u,int v){
        int pu= find(u);
        int pv= find(v);

        if(pu==pv){
            return false;
        }

        if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        }else if(rank[pv]<rank[pu]){
            parent[pv]=pu;
        }else{
            parent[pv]=pu;
            rank[pu]++;
        }
        
        return true;
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DSU dsu(n);
        int count=0;
        for(auto &c: connections){
            if(!(dsu.unionFind(c[0],c[1]))){
                count++;
            }
        }
        
        unordered_set<int>comp;
        for(int i=0;i<n;i++){
            comp.insert(dsu.find(i));
        }
        int visCount=comp.size()-1;

        return count>=visCount?visCount:-1;
    }
};