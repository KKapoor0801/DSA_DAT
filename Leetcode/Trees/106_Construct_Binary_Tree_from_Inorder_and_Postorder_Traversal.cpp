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
    
    TreeNode* binaryTree(int i1, int i2, vector<int>& inorder, int p1, int p2, vector<int>& postorder){
        
        if(i1 >= i2 || p1 >= p2) return nullptr;
        
        TreeNode* root = new TreeNode(postorder[p2-1]);
        
        auto it = find(inorder.begin() + i1, inorder.begin() + i2, postorder[p2-1]);
        int diff = it - (inorder.begin() + i1);
        
        root -> left = binaryTree(i1, i1 + diff, inorder, p1, p1 + diff, postorder);
        root -> right = binaryTree(diff + 1 + i1 , i2 ,inorder, diff + p1, p2 - 1, postorder);
         
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        if(n == 1){
            TreeNode *root = new TreeNode(inorder[n-1]);
            return root;
        }
        
        return binaryTree(0,n,inorder,0,n,postorder);
    }
};
