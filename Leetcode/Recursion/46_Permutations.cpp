class Solution {
public:
    
    void permutation(vector<int>& nums, vector<vector<int>>& res, int idx, int n){
        
        if(idx == n){
            res.push_back(nums);
            return;
        }
        
        int temp;
        for(int i = idx ; i<n ; i++){
            
            // SWAP
            temp = nums[idx]; 
            nums[idx] = nums[i];
            nums[i] = temp;
            
            permutation(nums,res,idx+1,n);
            
            // SWAP
            temp = nums[idx]; 
            nums[idx] = nums[i];
            nums[i] = temp;
        }
        
        return;
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        int idx = 0;
        
        permutation(nums,res,idx,n);
        
        return res;
        
    }
};
