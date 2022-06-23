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
    void checkSum(TreeNode* root, int targetSum, vector<vector<int>>& res, vector<int> curr, int currSum){
        
        int d = root -> val;
        currSum += d;
        curr.push_back(d);
        
        if(root -> left == NULL && root -> right == NULL){ //Condition to check if node is leaf node or not
            if(currSum == targetSum){
                res.push_back(curr);
                return;
            }
            else
                return;
        }
        
        if(root -> left != NULL)
            checkSum(root -> left, targetSum, res, curr, currSum);
        
        if(root -> right != NULL)
            checkSum(root -> right, targetSum, res, curr, currSum);
        
        return;
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<vector<int>> res;
        vector<int> curr;
        int currSum = 0;
        
        if(root == NULL)
            return res;
        
        checkSum(root,targetSum,res,curr,currSum);
        
        return res;
        
    }
};
