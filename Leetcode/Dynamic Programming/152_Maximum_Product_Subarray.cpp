class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int overall_max = nums[0];
        int n = nums.size();
        
        vector<int>dp_max_ending_here(n); // if nums[i] is +ve then it can make it even bigger if max is +ve
        vector<int>dp_min_ending_here(n); // if nums[i] is -ve then it can make it even bigger if min is -ve
        
        dp_max_ending_here[0] = nums[0];  
        dp_min_ending_here[0] = nums[0];
        
        // [2,-3,-4,-4,-5] --> use this eg for understanding the use of 2 dp arrays for max and min.
        
        for(int i = 1 ; i<n ; i++){
            
            dp_max_ending_here[i] = max(dp_max_ending_here[i-1] * nums[i], 
                                        max(dp_min_ending_here[i-1] * nums[i], nums[i]));
            
            dp_min_ending_here[i] = min(dp_min_ending_here[i-1] * nums[i], 
                                        min(dp_max_ending_here[i-1] * nums[i], nums[i]));
            
            overall_max = max(overall_max, dp_max_ending_here[i]);
        }
        
        return overall_max;
        
    }
};
