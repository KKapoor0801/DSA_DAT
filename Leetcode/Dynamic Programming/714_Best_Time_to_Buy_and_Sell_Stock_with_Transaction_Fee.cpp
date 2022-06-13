class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        
        vector<vector<int>> dp(prices.size(), vector<int>(2,0));
        
        dp[0][0] = (-1)*(prices[0] + fee); // 1st value of Buy Table
        dp[0][1] = 0; // 1st value of Sell Table
        
        int i;
        for(i = 1 ; i<prices.size() ; i++){
            
            //                HOLD                    BUY
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + (-1)*(prices[i] + fee));
            
            //               DONT DO          SELL
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i]);
            
        }
        return dp[prices.size()-1][1]; // FINAL PROFIT ATTAINED
    }
};
