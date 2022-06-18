int Solution::coinchange2(vector<int> &A, int B) {
    
    int n = A.size();
    int mod = 1000007;
    
    vector<int>dp_count(B+1,0);
    
    dp_count[0] = 1;
   
    for(int i = 0 ; i<n ; i++){
        
        for(int j = A[i] ; j<B+1 ; j++){
            dp_count[j] = (dp_count[j]%mod + dp_count[j-A[i]]%mod)%mod;
        }
    }
   return dp_count[B]%mod;

    //  vector<vector<int>>dp_count(n+1, vector<int>(B+1,0));
     
    //  for(int i = 0 ; i<n+1 ; i++){
    //      dp_count[i][0] = 1;
    //  }
     
    //  for(int i = 1 ; i<n+1 ; i++){
    //      for(int j = 1 ; j<B+1 ; j++){
    //          if(A[i-1] > j){
    //              dp_count[i][j] = dp_count[i-1][j]%mod;
    //          }
    //          else{
    //              dp_count[i][j] = (dp_count[i][j-A[i-1]]%mod + dp_count[i-1][j]%mod)%mod;
    //          }
    //      }
    //  }
    //  return dp_count[n][B]%mod;
}
