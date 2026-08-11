/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool callAcl(TreeNode* root,TreeNode* s){
        if(!root) return false;

        if(root==s) return true;

        return callAcl(root->left,s) || callAcl(root->right,s);
    }
    void lca(TreeNode* root,TreeNode* p,TreeNode* q,TreeNode* & ans){
        if(!root) return;

        if(root==p){
            if(callAcl(root,q)) ans=root;
        }

        if(root==q){
            if(callAcl(root,p)) ans=root;
        }

        if(callAcl(root->left,p) && callAcl(root->right,q)) ans= root;

        if(callAcl(root->left,q) && callAcl(root->right,p)) ans= root;
        
        lca(root->left,p,q,ans);
        lca(root->right,p,q,ans);


    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans= nullptr;
        lca(root,p,q,ans);
        return ans;
    }
};