class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n= strs.size();
        if(strs.empty()){
            return "";
        }

        if(n==1){
            return strs[0];
        }

        string result="";
        int minL= min(strs[0].size(),strs[1].size());
        for(int i=0;i<minL;i++){
            if(strs[0][i]==strs[1][i]){
                result+= strs[0][i];
            }else{
                break;
            }
        }

        if(result.empty()){
            return "";
        }

        for(int i=2;i<n;i++){
            int j=0;
            while(j<result.size() && j<strs[i].size()){
                if(result[j]!=strs[i][j]){
                    result= strs[i].substr(0,j);
                    break;
                }
                j++;
            }
            if(j==strs[i].size()){
                result= strs[i];
            }
        }

        return result;
    }
};