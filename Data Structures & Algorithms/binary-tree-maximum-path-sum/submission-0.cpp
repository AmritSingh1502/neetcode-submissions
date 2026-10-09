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
    int dfs(TreeNode* node , int& maxSum) {
        if(node == nullptr) return 0;

        // find max path sum of left and right subtree
        // if a subtree sum is -ve we drop it entirely by taking max(0, ..);
        int left = max(0, dfs(node->left, maxSum));
        int right = max(0, dfs(node->right, maxSum));


        // calculate the maximum path sum that splits at the current node
        int localSum = node->val + left + right;

        maxSum = max(maxSum , localSum);

        // return sum
        return node->val + max(left, right);

    }

public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        dfs(root, maxSum);
        return maxSum;
    }
};
