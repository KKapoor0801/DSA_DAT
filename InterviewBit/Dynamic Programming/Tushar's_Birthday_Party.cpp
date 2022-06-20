
int Solution::solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    
    int n = *max_element(A.begin(),A.end());
    vector<int>dp(n+1,INT_MAX);
    
    dp[0] = 0;
    
    for(int i = 1 ; i<n+1 ; i++){
        
        for(int j = 0 ; j<B.size() ; j++){
            
            if(B[j] <= i){
                dp[i] = min(dp[i] , C[j] + dp[i-B[j]]);
            }
            
        }
        
    }
    
    int cost = 0;
    
    for(int i = 0 ; i<A.size() ; i++){
        cost += dp[A[i]];
    }
    return cost;
} 
