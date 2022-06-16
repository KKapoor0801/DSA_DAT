class Solution {
public:
    
    int wb(string s, set<string>& wordDict, vector<int>& dp, int pos){
        
        if(pos == s.size())
            return 1;
        
        if(dp[pos] != -1)
            return dp[pos];
        
        string temp = "";
        for(int i = pos; i<s.size() ; i++){
            temp += s[i];
            
            if(wordDict.find(temp) != wordDict.end())
                if(wb(s,wordDict,dp,i+1)){
                    dp[pos] = 1;
                    return dp[pos];
            }
        }
        dp[pos] = 0;
        return dp[pos];
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        bool ans;
        int n = s.size();
        vector<int>dp(n,-1);
        
        set<string> st;
        for(auto a: wordDict){
            st.insert(a);
        }
        
        ans = wb(s,st,dp,0);
        
        return (bool)ans;
    }
};
