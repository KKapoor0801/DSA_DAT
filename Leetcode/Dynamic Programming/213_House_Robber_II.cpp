class Solution {
public:
    
    int houseRobber(vector<int>& nums, int i, int end, vector<int>& dp){
        
        if(i >= end){
            return 0;
        }
        
        if(dp[i] != -1)
            return dp[i];
            
        int stolenHouseMoney = nums[i] + houseRobber(nums,i+2,end,dp);  // INCLUDE
        int skippedHouseMoney = houseRobber(nums,i+1,end,dp); // EXCLUDE
        
        dp[i] = max(stolenHouseMoney, skippedHouseMoney);
        
        return dp[i];
        
    }
    
    int rob(vector<int>& nums) {
        vector<int> dp1(nums.size(),-1);
        vector<int> dp2(nums.size(),-1);
        
        if(nums.size() == 1) return nums[0];
        
        // First and Last can never come in solution together so it can
        // either be first to n-2 elts except last
        // or 1 to last elts except first 
        int start,end;
        
        // nums is from 0 to n-2
        start = 0;
        end = nums.size() - 1;
        int maxAmt1 = houseRobber(nums,start,end,dp1);
        
        // nums is from 1 to n-1
        start = 1;
        end = nums.size();
        int maxAmt2 = houseRobber(nums,start,end,dp2);
        
        cout<<maxAmt1<<"and"<<maxAmt2<<endl;
        
        int maxAmt = max(maxAmt1, maxAmt2);
        
        return maxAmt;
    }
};
