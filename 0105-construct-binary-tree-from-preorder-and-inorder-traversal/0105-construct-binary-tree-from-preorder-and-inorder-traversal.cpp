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
    unordered_map<int, int> inorder_map;
    int preorder_index = 0;

    TreeNode* buildTreeHelper(vector<int>& preorder, int inorder_left, int inorder_right) {
        if (inorder_left > inorder_right) {
            return nullptr;
        }

        int root_val = preorder[preorder_index++];
        TreeNode* root = new TreeNode(root_val);

        int inorder_index = inorder_map[root_val];

        root->left = buildTreeHelper(preorder, inorder_left, inorder_index - 1);
        root->right = buildTreeHelper(preorder, inorder_index + 1, inorder_right);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        inorder_map.clear();
        preorder_index = 0;
        
        for (int i = 0; i < inorder.size(); ++i) {
            inorder_map[inorder[i]] = i;
        }

        return buildTreeHelper(preorder, 0, inorder.size() - 1);
    }
};