class Solution {
public:
    
    int houseRobber(vector<int>& nums, int i, vector<int>& dp){
        
        // Base Case
        if(i >= nums.size())
            return 0;
        
        // Memoization
        if(dp[i] != -1)
            return dp[i];
        
        int stolenHouseMoney = nums[i] + houseRobber(nums,i+2,dp);
        int skippedHouseMoney = houseRobber(nums,i+1,dp);
        
        dp[i] = max(stolenHouseMoney, skippedHouseMoney);
        return dp[i];
        
    }
    
    int rob(vector<int>& nums) {
        
        vector<int> dp(nums.size(),-1);
        int maxAmt = houseRobber(nums,0,dp);
        
        return maxAmt;
    }
};
