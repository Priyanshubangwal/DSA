class Solution {
public:
    void funcPrev(int n,stack<int>& st1,vector<int>& prevSmaller,vector<int>& heights){
        for(int i=0;i<n;i++){
            while(!st1.empty() && heights[i]< heights[st1.top()]){
                st1.pop();
            }

            if(st1.empty()){
                prevSmaller.push_back(-1);
            }else{
                prevSmaller.push_back(st1.top());
            }

            st1.push(i);
        }

        return;
    }

    void funcNext(int n,stack<int>& st,vector<int>& nextSmaller,vector<int>& heights){
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[i]<=heights[st.top()]){
                st.pop();
            }

            if(st.empty()){
                nextSmaller.push_back(n);
            }else{
                nextSmaller.push_back(st.top());
            }

            st.push(i);
        }

        reverse(nextSmaller.begin(), nextSmaller.end());

        return;
    }

    int largestRectangleArea(vector<int>& heights) {

        vector<int>nextSmaller;
        vector<int>prevSmaller;
        int n= heights.size();
        stack<int>st,st1;
        funcNext(n,st,nextSmaller,heights);
        funcPrev(n,st1,prevSmaller,heights);
        int area= 0;
        for(int i=0;i<n;i++){
            area= max(area, heights[i] * (nextSmaller[i]-prevSmaller[i]-1));
        }

        return area;
    }
};