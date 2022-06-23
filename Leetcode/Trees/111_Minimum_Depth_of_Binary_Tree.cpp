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
    
    void minLength(TreeNode* root, int currLen, int& minLen){
        
        currLen++;
        
        if(root -> left == NULL && root -> right == NULL){
             minLen = min(minLen, currLen);
             return;
        }
        
        if(root -> left != NULL)
            minLength(root -> left, currLen, minLen);
        
        if(root -> right != NULL)
            minLength(root -> right, currLen, minLen);
        
        return;
    }
    
    int minDepth(TreeNode* root) {
        
        if(root == NULL)
            return 0;
        
        int currLen = 0, minLen = INT_MAX;
        
        minLength(root,currLen,minLen);
        return minLen;
    }
};
