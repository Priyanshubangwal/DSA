class Solution {
public:
    bool judgeSquareSum(int c) {
        long long r= ceil(sqrt(c));
        long long l=0;
        
        bool k= false;
        while(l<=r){
            if(l*l+ r*r==c){
                k=true;
                break;
            }else if(l*l+ r*r<c){
                l++;
            }else{
                r--;
            }
        }

        return k;
    }
};