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

class Codec {
private:
    void serializeHelper(TreeNode* node , ostringstream& out){
        if(node == nullptr){
            out << "N,";
            return;
        }

        out << node->val << ",";
        serializeHelper(node->left, out);
        serializeHelper(node->right, out);
    }

    TreeNode* deserializeHelper(queue<string>& q) {
        string val = q.front();
        q.pop();

        if(val == "N") return nullptr;

        TreeNode* node = new TreeNode(stoi(val));
        node->left = deserializeHelper(q);
        node->right = deserializeHelper(q);

        return node;
    }

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serializeHelper(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        queue<string> q;
        string val;

        // split the string by comma and push into a queue
        while(getline(in, val , ',')) {
            q.push(val);
        }

        return deserializeHelper(q);
    }
};
