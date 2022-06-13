class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        // Corner Case
        if(n < 2) return 0;
        
        vector<vector<int>> dp(n,vector<int>(2,0));
        
        // Base Case 1
        dp[0][0] = (-1)*prices[0];
        dp[0][1] = 0;
        
        // Base Case 2
        dp[1][0] = max(dp[0][0], dp[0][1] - prices[1]);
        dp[1][1] = max(dp[0][1], dp[0][0] + prices[1]);
    
        for(int i = 2 ; i<n ; i++){
                //          HOLD      BUY if previous is not sell
            dp[i][0] = max(dp[i-1][0], dp[i-2][1] - prices[i]);
            
                //          DONT DO      SELL
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i]);  
        }
        return dp[n-1][1];
    }
};
