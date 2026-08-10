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
    int maxDepth(TreeNode* root) {
        int count=0;
        queue<TreeNode*>q;
        if(!root){
            return 0;
        }
        q.push(root);
        while(!q.empty()){
            int size= q.size();
            count++;
            while(size--){
                TreeNode* s= q.front();
                q.pop();

                if(s->left){
                    q.push(s->left);
                }

                if(s->right){
                    q.push(s->right);
                }
            }
        }

        return count;
    }
};