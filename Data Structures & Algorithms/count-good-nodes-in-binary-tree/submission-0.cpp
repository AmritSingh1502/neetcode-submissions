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
private:
    int dfs(TreeNode* node, int max){
        if(node == nullptr) return 0;

        int res = 0;

        if(node->val >= max){
            res = 1;
            max = node->val;
        }

        res += dfs(node->left , max);
        res += dfs(node->right, max);

        return res;
    }

public:
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};
