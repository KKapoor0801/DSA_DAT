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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q; // BFS or Level Order Traversal
        
        if(root == NULL)
            return res;
        int level = 0; // Odd Levels have alternate nodes and even had same order nodes
        
        q.push(root);
        
        while(!q.empty()){
            
            int n = q.size();
            vector<int> curr;
            
            for(int i = 0 ; i<n ; i++){
                
                TreeNode* temp = q.front();
                q.pop();
                curr.push_back(temp -> val);
                
                if(temp -> left != NULL) q.push(temp -> left);
                if(temp -> right != NULL) q.push(temp -> right);
                
            }
            
            if(level % 2 == 0) // To check if level is even
                res.push_back(curr);
            
            else{
                reverse(curr.begin(), curr.end()); // STL func to reverse a vector
                res.push_back(curr);
            }
            
            level++;
        }
        return res;
    }
};
