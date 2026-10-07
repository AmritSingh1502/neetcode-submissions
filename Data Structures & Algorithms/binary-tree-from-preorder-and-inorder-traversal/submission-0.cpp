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
    TreeNode* build(vector<int>& preorder, unordered_map<int,int>& inorderMap, int& preorderIndex, int inLeft, int inRight){


        if(inLeft > inRight) return nullptr;

        // pick the currnt root from the preOrder array
        int rootVal = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootVal);

        // find the root's position in the inorder array to split the tree
        int mid = inorderMap.at(rootVal);

        // build the left and right subtree
        root->left = build(preorder, inorderMap, preorderIndex, inLeft, mid - 1);
        root->right = build(preorder, inorderMap, preorderIndex, mid + 1, inRight);

        return root;

    }



public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> inorderMap;
        for(int i = 0; i< inorder.size(); i++){
            inorderMap[inorder[i]] = i;
        }

        int preorderIndex = 0;
        return build(preorder, inorderMap, preorderIndex, 0 , inorder.size()-1);
    }
};
