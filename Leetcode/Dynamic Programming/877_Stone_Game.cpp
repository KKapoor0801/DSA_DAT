class Solution {
public:
       // TC = O(n^2) and SC = O(n^2)
       int winner(int i, int j, vector<int>& piles, vector<vector<int>>& dp){
           
           if(i>j)
               return 0;
           
           if(dp[i][j] != -1)
               return dp[i][j];
           
           dp[i][j] = max((piles[i] - winner(i+1,j,piles,dp)), (piles[j] - winner(i,j-1,piles,dp)));
           return dp[i][j];
           
       }
    
       bool stoneGame(vector<int>& piles){
           
           int n = piles.size();
           vector<vector<int>>dp(n,vector<int>(n,-1));
           
           return winner(0,n-1,piles,dp)>0 ? 1 : 0;
       }
    
    
            
            
    // TC = O(1) and SC = O(1) 
            
    // bool stoneGame(vector<int>& piles) {
    //     return 1;  // ALICE WILL WIN ALWAYS 
    // }
};
