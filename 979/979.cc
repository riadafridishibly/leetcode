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
    int distributeCoins(TreeNode* root) {
        int result = 0;
        dfs(root, result);
        return result;
    }
    
    int dfs(TreeNode* root, int& res) {
        if (!root) return 0;
        auto l = dfs(root->left, res);
        auto r = dfs(root->right, res);
        res += abs(r) + abs(l);
        return root->val + l + r - 1;
    }
};
