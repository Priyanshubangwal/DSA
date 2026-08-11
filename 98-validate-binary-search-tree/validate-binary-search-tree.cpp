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
    void isValid(TreeNode* root,vector<int>& ans){
        if(!root){
            return;
        }

        isValid(root->left,ans);
        ans.push_back(root->val);
        isValid(root->right,ans);

        return;
    }
    bool isValidBST(TreeNode* root) {
        vector<int>ans;
        isValid(root,ans);
        bool ann= true;
        for(int i=1;i<ans.size();i++){
            if(ans[i-1]>=ans[i]){
                ann= false;
                break;
            }
        }

        return ann;
    }
};