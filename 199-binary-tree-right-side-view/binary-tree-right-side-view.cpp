/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        queue<TreeNode*>q;
        if(!root){
            return {};
        }
        q.push(root);
        while(!q.empty()){
            int size= q.size();
            bool key= false;
            while(size--){
                TreeNode* s= q.front();
                q.pop();
                if(key==false){
                    key=true;
                    ans.push_back(s->val);
                }

                if(s->right){
                    q.push(s->right);
                }

                if(s->left){
                    q.push(s->left);
                }
            }
        }

        return ans;
    }
};