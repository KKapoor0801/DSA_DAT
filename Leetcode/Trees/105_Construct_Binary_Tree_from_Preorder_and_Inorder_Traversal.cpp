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
    
    TreeNode* binaryTree(int i1, int i2, vector<int>& inorder, int p1, int p2, vector<int>& preorder){
        
        if(i1 >= i2 || p1 >= p2) return nullptr;
        
        TreeNode *root = new TreeNode(preorder[p1]);
        
        auto it = find(inorder.begin() + i1, inorder.begin() + i2, preorder[p1]);
        int diff = it - (inorder.begin() + i1);
        
        root -> left = binaryTree(i1, i1 + diff, inorder, p1 + 1, p2, preorder);
        root -> right = binaryTree(i1 + diff + 1, i2, inorder, p1 + diff + 1, p2, preorder);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        if(n == 1){
            TreeNode* root = new TreeNode(inorder[0]);
            return root;
        }
        
        return binaryTree(0,n,inorder,0,n,preorder);
    }
};
