class Solution {
public:
    
    int climbingWays(int n, int i, vector<int> &dp){
        
        // BASE CASE 1
        if(i == n)
            return 1;
        
        // BASE CASE 2
        if(i > n)
            return 0;
        
        // MEMOIZATION
        if(dp[i] != -1)
            return dp[i];
        
        int OneStep = climbingWays(n,i+1,dp);
        int TwoStep = climbingWays(n,i+2,dp);
        
        dp[i] = OneStep + TwoStep;
        return dp[i];
        
    }
    
    int climbStairs(int n) {
        
        vector<int> dp(n,-1);
        int ways = 0;
        
        ways = climbingWays(n,0,dp);
        
        return ways;
    }
};
