class Solution {
public:
    int strStr(string haystack, string needle) {
        int n= needle.size();
        int m= haystack.size();

        int j=0;
        int i=0;
        int ans=-1;
        while(j<m){
            i=0;
            int p=-1;
            int q=j;
            while(i<n){
                if(needle[i]==haystack[j]){
                    if(p==-1){
                        p=j;
                    }
                    i++;
                    j++;
                }else{
                    j=q;
                    break;
                }
            }

            if(i>=n){
                ans=p;
                break;
            }
            j++;
        }

        return ans;

    }
};