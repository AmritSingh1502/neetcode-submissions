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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr = root;

        while(curr != nullptr){

            // case 1 : both nodes are in the right subtree
            if(p->val > curr->val && q->val > curr->val){
                curr = curr->right;
            }
            // case 2
            else if(p->val < curr->val && q->val < curr->val){
                curr = curr->left;
            }
            else {
                // case one is greater and one is less or same then we got the split point
                return curr;
            }
        }

        return curr;
    }
};
