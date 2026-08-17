class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n= code.size();
        vector<int>ans(n);
        if(k==0){
            for(int i=0;i<n;i++){
                ans[i]=0;
            }
        }else if(k>0){
            for(int i=0;i<n;i++){
                int sum=0;
                int j=(i+1)%n;
                int p=k;
                while(p!=0 && j<2*n){
                    sum+= code[j];
                    j= (j+1)%n;
                    p--;
                }

                ans[i]= sum;
            }
        }else{
            for(int i=0;i<n;i++){
                int sum=0;
                int p=-k;
                int j=(i+ (n-p))%n;
                while(p!=0 && j<2*n){
                    sum+= code[j];
                    j=(j+1)%n;
                    p--;
                }

                ans[i]= sum;
            }
        }

        return ans;
    }
};