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
    int countNodes(TreeNode* root) {
        
        TreeNode *right_node = root, *left_node = root;
        int height_right = 0, height_left = 0;
        
        while(right_node != NULL){
            height_right++;
            right_node = right_node -> right;
        }
        
        while(left_node != NULL){
            height_left++;
            left_node = left_node -> left;
        }
        
        if(height_right == height_left)
            return ((int)pow(2,height_right) - 1);  // return ((1<<height_right) - 1)
        
        return (1 + countNodes(root -> left) + countNodes(root -> right));
    }
};
