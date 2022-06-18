class Solution {
public:
    // SIMILAR TO COIN CHANGE ---> UNBOUNDED KNAPSACK TYPE PROBLEM
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        
        vector<vector<int>>dp_count(n+1,vector<int>(amount+1,0));
        
        for(int i = 0 ; i<n+1 ; i++){
            dp_count[i][0] = 1;
        }
        
        for(int i = 1 ; i<n+1 ; i++){
            
            for(int j = 1 ; j<amount+1 ; j++){
                
                if(coins[i-1] > j)
                    dp_count[i][j] = dp_count[i-1][j];
                else
                    dp_count[i][j] = dp_count[i][j-coins[i-1]] + dp_count[i-1][j];
            }
            
        }
        return dp_count[n][amount];
        
        
        //1-D DP SOLUTION FROM INTERVIEWBIT
//             int n = A.size();
//     int mod = 1000007;
    
//     vector<int>dp_count(B+1,0);
    
//     dp_count[0] = 1;
   
//     for(int i = 0 ; i<n ; i++){
        
//         for(int j = A[i] ; j<B+1 ; j++){
//             dp_count[j] = (dp_count[j]%mod + dp_count[j-A[i]]%mod)%mod;
//         }
//     }
//    return dp_count[B]%mod;

    }
};
