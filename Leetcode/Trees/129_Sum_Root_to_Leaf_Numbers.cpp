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
    int ans = 0;
    int pathSum(TreeNode* root, TreeNode* temp, int currVal){
        
        int d = temp -> val;
        currVal = currVal*10 + d;
        
        if(temp->left == NULL && temp->right == NULL){
            ans += currVal;
            return ans;
        }
        
        if(temp -> left != NULL){
            int path1 = pathSum(root,temp -> left,currVal);
        }
        
        if(temp -> right != NULL){
            int path2 = pathSum(root,temp -> right,currVal);
        }
        
        return ans;
    }
    
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        
        if(root == NULL)
            return sum;
        
        TreeNode *temp = root;
        int currVal = 0;
        
        sum = pathSum(root,temp,currVal);
        
        return sum;
    }
};
