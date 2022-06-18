int Solution::solve(vector<int> &A, vector<int> &B, int C) {
    
    int n = B.size();
    vector<vector<int>>dp_ks(n+1, vector<int>(C+1,0));
    
    for(int i = 1 ; i<n+1 ; i++){
        
        for(int j = 1 ; j<C+1 ; j++){
            
            if(B[i-1] > j){
                dp_ks[i][j] = dp_ks[i-1][j];
            }
            else{
                dp_ks[i][j] = max(dp_ks[i-1][j], A[i-1] + dp_ks[i-1][j-B[i-1]]);
            }
        }
        
    }
    return dp_ks[n][C];
    
}
