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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        
        if(root == NULL)
            return res;
        
        q.push(root);
        
        while(!q.empty()){
            
            int n = q.size();
            vector<int> curr;
            
            for(int i = 0 ; i<n ; i++){
                
                TreeNode *temp = q.front();
                q.pop();
                curr.push_back(temp -> val);
                
                if(temp -> left != NULL) q.push(temp -> left);
                if(temp -> right != NULL) q.push(temp -> right);
            }
            res.push_back(curr);
        }
        return res;
    }
};
