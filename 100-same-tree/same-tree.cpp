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
    bool checkSame(TreeNode* p, TreeNode* q){
        if(!p && q || p && !q) return false;

        if(!p && !q) return true;

        return (p->val == q->val) && checkSame(p->left,q->left) && checkSame(p->right,q->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return checkSame(p,q);
    }
};