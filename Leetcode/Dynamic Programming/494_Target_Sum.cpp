class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // DP METHOD
        int n = nums.size();
        int totalSum = 0;
        for(int i = 0 ; i<n ; i++){
            totalSum += nums[i];
        }
        
        if((totalSum + target)%2 != 0) //Because nums has only integers
            return 0;
        
        int pos_subset_sum = (totalSum + target)/2;
        
        if((totalSum + target) < 0) //Because nums[i] are only positive (>=0)
            return 0;
        
        vector<vector<int>>dp_count((n+1), vector<int>((pos_subset_sum+1),0));
        
        for(int i = 0 ; i<n+1 ; i++){
            dp_count[i][0] = 1;
        }
        
        // Loop to check the number of subsets that sum up to some target and can be made from the array elts
        for(int i = 1 ; i<n+1 ; i++){
            
            for(int j = 0 ; j<pos_subset_sum+1 ; j++){
                
                if(nums[i-1] > j)
                    dp_count[i][j] = dp_count[i-1][j];
                else
                    dp_count[i][j] = dp_count[i-1][j-nums[i-1]] + dp_count[i-1][j];
            }
            
        }
    
        return dp_count[n][pos_subset_sum];
    
    
    // RECURSIVE METHOD - GOT SUBMITTED BUT NOT VERY FEASIBLE
    
//     int targetSum(vector<int>& nums, int target, int i, int end, int sum){
        
//         // BASE CASE 1
//         if(i == end && sum == target)
//             return 1;
        
//         // BASE CASE 2
//         if(i == end && sum != target)
//             return 0;
            
//         // RECURSIVE STEP
//         int ways = targetSum(nums,target,i+1,end,sum+nums[i]) + targetSum(nums,target,i+1,end,sum-nums[i]);
        
//         return ways;
//     }
    
//     int findTargetSumWays(vector<int>& nums, int target) {
        
//         int n = nums.size();
//         int sum = 0;
        
//         int count = targetSum(nums,target,0,n,sum);
        
//         return count;
        
    }
};
