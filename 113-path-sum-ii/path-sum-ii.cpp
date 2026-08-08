class Solution {
public:
    void dfs(TreeNode* root, int sum, int targetSum, 
             vector<int>& path, vector<vector<int>>& res) {
        if (!root) return;

        path.push_back(root->val);
        sum += root->val;

        if (!root->left && !root->right && sum == targetSum) {
            res.push_back(path);
        }

        dfs(root->left, sum, targetSum, path, res);
        dfs(root->right, sum, targetSum, path, res);

        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(root, 0, targetSum, path, res); 
        return res;
    }
};
