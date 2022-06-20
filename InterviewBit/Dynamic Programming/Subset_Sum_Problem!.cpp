int Solution::solve(vector<int> &A, int B) {
    
    int n = A.size();
    vector<vector<int>>dp(n+1,vector<int>(B+1,0));
    
    for(int i = 0 ; i<n+1 ; i++){
        dp[i][0] = 1;
    }
    
    for(int i = 1 ; i<n+1 ; i++){
        
        for(int j = 1 ; j<B+1 ; j++){
            
            if(A[i-1] > j){
                dp[i][j] = dp[i-1][j]; 
            }
            else{
                dp[i][j] = dp[i-1][j] || dp[i-1][j-A[i-1]];
            }
        }
        
    }
    return dp[n][B] > 0 ? 1 : 0; 
}
