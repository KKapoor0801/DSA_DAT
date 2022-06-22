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
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int>res; // To store the final result
        
        queue<TreeNode*> q; // Used for Level Order Traversal of Tree
        
        if(root == NULL)
            return res;
        
        q.push(root);
        
        while(!q.empty()){
            
            vector<int>curr;
            int n = q.size();
            
            for(int i = 0 ; i<n ; i++){
                TreeNode* temp = q.front();
                q.pop();
                curr.push_back(temp -> val);
                
                if(temp -> left != NULL) q.push(temp -> left);
                if(temp -> right != NULL) q.push(temp -> right);
            }
            res.push_back(curr[n-1]); // To store only the elements which are visible when viewed from right side
            
        }
        
        return res;
    }
};
