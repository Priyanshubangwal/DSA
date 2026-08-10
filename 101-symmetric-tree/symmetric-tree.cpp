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
    void callRes(TreeNode* root, vector<int>& res){
        if(!root){
            res.push_back(101);
            return;
        }

        callRes(root->right,res);
  
        callRes(root->left,res);
        


        res.push_back(root->val);
    }
    void callAns(TreeNode* root,vector<int>& ans){
        if(!root){
            ans.push_back(101);
            return;
        }

        callAns(root->left,ans);
        callAns(root->right,ans);

        ans.push_back(root->val);
    }
    bool isSymmetric(TreeNode* root) {
        vector<int>ans;
        vector<int>res;
        callAns(root->left,ans);
        callRes(root->right,res);

        if(ans==res){
            return true;
        }

        return false;
    }
};