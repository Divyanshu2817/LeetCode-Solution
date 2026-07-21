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
    int index=0;
    TreeNode* bstpreorder(vector<int>& preorder,int range){
        
        if(index==preorder.size()|| preorder[index]>range){
            return nullptr;
        }
        TreeNode* root=new TreeNode(preorder[index]);
        index++;
        root->left = bstpreorder(preorder, root->val); 
        root->right = bstpreorder(preorder, range); 
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
       int range=INT_MAX;
       return bstpreorder(preorder,range);
}   
};