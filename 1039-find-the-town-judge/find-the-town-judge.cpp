class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>score(n+1,0);
        
        for(auto &v: trust){
            int a= v[0];
            int b= v[1];

            score[a]--;
            score[b]++;
        }

        for(int i=1;i<=n;i++){
            if(score[i]==n-1){
                return i;
            }
        }
        
        return -1;
    }
};