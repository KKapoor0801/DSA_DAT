class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
      
        int n = coins.size();
        
        if(amount == 0)
            return 0;
        
        vector<vector<int>>dp_ways(n+1, vector<int>(amount+1,0));
        
        for(int j = 1 ; j<amount+1 ; j++)
            dp_ways[0][j] = INT_MAX - 1;
        
        for(int i = 1 ; i<n+1 ; i++){
            
            for(int j = 1 ; j<amount+1 ; j++){
                
                if(coins[i-1] > j)
                    dp_ways[i][j] = dp_ways[i-1][j];
                else
                    dp_ways[i][j] = min(dp_ways[i-1][j], (1 + dp_ways[i][j-coins[i-1]]));
                
            }
            
        }
        return (dp_ways[n][amount] > 1e4 ? -1 : dp_ways[n][amount]); //1e4 = 1*10^4 = max possibe amount as per ques
    }
};
