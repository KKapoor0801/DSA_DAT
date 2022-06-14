class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0' || s.size() == 0)
            return 0;
        
        if(s[0] == '*' && s.size() == 1)
            return 9;
        
        long int mod = 1000000007;
        int n = s.size();
        
        vector<long>dp(n+1);
        dp[0] = 1;
        
        if(s[0] == '*')
            dp[1] = 9;
        else 
            dp[1] = 1; 
        
        for(long i = 2 ; i<=n ; i++){
            
            // Grouping 1 character as a single block with the given conditions
            if(s[i-1] == '*')
                dp[i] = (dp[i] + (9*dp[i-1])%mod)%mod;
            
            else if(s[i-1] >= '1' && s[i-1] <= '9')
                dp[i] = (dp[i] + (dp[i-1])%mod)%mod;
            
            // Grouping 2 characters together with the given conditions
            if(s[i-2] == '*'){
                if(s[i-1] == '*')
                    dp[i] = (dp[i] + (15*dp[i-2])%mod)%mod;
                else if(s[i-1] <= '6')
                    dp[i] = (dp[i] + (2*dp[i-2])%mod)%mod;
                else
                    dp[i] = (dp[i] + (dp[i-2])%mod)%mod;
            }
            
            else if(s[i-2] == '1'){
                if(s[i-1] == '*')
                    dp[i] = (dp[i] + (9*dp[i-2])%mod)%mod;
                
                else if(s[i-1] >= '0' && s[i-1] <= '9')
                    dp[i] = (dp[i] + (dp[i-2])%mod)%mod;
            }
            
            else if(s[i-2] == '2'){
                if(s[i-1] == '*')
                    dp[i] = (dp[i] + (6*dp[i-2])%mod)%mod;
                else if(s[i-1] <= '6')
                    dp[i] = (dp[i] + (dp[i-2])%mod)%mod;
            }
            
        }
        return dp[n];
    }
};
