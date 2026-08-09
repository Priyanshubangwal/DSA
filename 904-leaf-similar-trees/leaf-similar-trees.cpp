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
    void call1Trees(TreeNode* root2,vector<int>& res){
        if(!root2->left && !root2->right){
            res.push_back(root2->val);
        }
        
        if(root2->left){
         call1Trees(root2->left,res);
        }
        
        if(root2->right){
        call1Trees(root2->right,res);
        }

        return;
    }
    void callTrees(TreeNode* root1,vector<int>& ans){
        if(!root1->left && !root1->right){
            ans.push_back(root1->val);
        }
        
        if(root1->left){
         callTrees(root1->left,ans);
        }
        
        if(root1->right){
        callTrees(root1->right,ans);
        }

        return;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>ans;
        vector<int>res;

        callTrees(root1,ans);
        call1Trees(root2,res);

        if(ans==res){
            return true;
        }

        return false;
    }
};