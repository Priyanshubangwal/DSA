class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        int n= s.size();
        if(n==1){
            return false;
        }
        int i=n-1;
        while(i>=0){
            if(s[i]==')' || s[i]==']' || s[i]=='}'){
                st.push(s[i]);
            }else{
                if(!st.empty() && (s[i]=='(' && st.top()==')')){
                    st.pop();
                }else if(!st.empty() && (s[i]=='[' && st.top()==']')){
                    st.pop();
                }else if(!st.empty() && (s[i]=='{' && st.top()=='}')){
                    st.pop();
                }else{
                    break;
                }
            }
            i--;
        }

        if(i<0 && st.empty()){
            return true;
        }

        return false;

    }
};