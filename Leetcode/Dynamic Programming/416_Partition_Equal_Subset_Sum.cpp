class Solution {
public:
    
    // SIMILAR TO LEETCODE 494 - TARGET SUM ---> HERE TARGET WAS 0 BCZ THE SUBSET SUMS WERE SAME SO S1 - S2 = 0
    
    bool canPartition(vector<int>& nums) {
        
        int target = 0;
        int sum = 0;
        int n = nums.size();
        for(int i = 0 ; i<n ; i++){
            sum += nums[i];
        }
        
        if(sum%2 != 0)
            return false;
        
        int sum_subset_one = (sum + target)/2; 
        
        vector<vector<unsigned int>>dp_check(n+1, vector<unsigned int>((sum_subset_one+1),0)); // Error while using signed int for some reason
        
        for(int i = 0 ; i<n+1 ; i++)
            dp_check[i][0] = 1;
        
        // Loop to check the number of subsets that can be formed for a given target from the elts of nums
        
        for(int i = 1 ; i<n+1 ; i++){
            
            for(int j = 1 ; j<sum_subset_one+1 ; j++){
                
                if(nums[i-1] > j) 
                    dp_check[i][j] = dp_check[i-1][j]; //Exclude nums[i]
                else
                    dp_check[i][j] = dp_check[i-1][j] + dp_check[i-1][j-nums[i-1]]; //Include or Exclude nums[i]
            
            }
            
        }
            return dp_check[n][sum_subset_one]; //If 0 then false otherwise true for any other value. Mostly the value will be either 0 or 2 because we want to check if it can be splitted into 2 subsets or not.
    }
};
