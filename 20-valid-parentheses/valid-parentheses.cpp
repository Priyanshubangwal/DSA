class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        bool k= true;
        int i=s.length()-1;
        while(i>=0){
            if(s[i]==')' || s[i]==']' || s[i]=='}'){
                st.push(s[i]);
            }else{
                if(!st.empty() && s[i]=='(' && st.top()==')' || !st.empty() && s[i]=='[' && st.top()==']' || !st.empty() && s[i]=='{' && st.top()=='}') {
                    st.pop();
                }else{
                   k=false;
                   break;
                }
                
            }
            i--;
        }
        
        if(!st.empty() || i>0){
            k=false;
        }
        
        return k;
    }
};