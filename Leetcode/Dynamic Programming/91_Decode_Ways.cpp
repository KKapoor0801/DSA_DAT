class Solution {
public:

    // ITERATIVE SOLUTION --- BETTER APPROACH
    int numDecodings(string s){
        
        if(s[0] == '0' || s.size() == 0) return 0;
        int n = s.size();
        
        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i = 2 ; i<=n ; i++){
            if(s[i-1] >= '1' && s[i-1] <= '9') // Can be treated as a single decoding
                dp[i] = dp[i-1];
            
            // Can be converted in a block of 2 characters if the subsequent conditions are true
            if(s[i-2] == '1')
                dp[i] += dp[i-2];
            else if(s[i-2] == '2' && s[i-1] >=48 && s[i-1] <= 54)
                dp[i] += dp[i-2];
            
            cout<<dp[i]<<endl;
        }
        
        return dp[n];

    // RECURSIVE SOLUTION
    
//     int Decode(string s, int i, vector<int>& dp){
        
//         if(i >= s.size()){
//             return 1;
//         }
        
//         if(s[i] == '0')
//             return 0;
        
//         if(i == s.size()-1) 
//             return 1;
        
//         if(dp[i] != -1)
//             return dp[i];
        
//         if(s[i] == '1' || (s[i] == '2' && s[i+1] >=48 && s[i+1] <= 54)){
//             dp[i] = Decode(s,i+1,dp) + Decode(s,i+2,dp);
//             return dp[i];
//         }
//         else{
//             dp[i] = Decode(s,i+1,dp);
//             return dp[i];
//         }
//     }
    
//     int numDecodings(string s) {
//         if(s[0] == '0') return 0;
        
//         if(s.size() == 1) return 1;
        
//         int ways = 0;
//         vector<int> dp(s.size(),-1);
        
//         ways = Decode(s,0,dp);
        
//         return ways;
    }
};
