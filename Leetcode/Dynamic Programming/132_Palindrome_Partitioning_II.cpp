class Solution {
public:
    
    bool isPalin(string &str,int start, int end){  // Function to check if a string is palindrome or not between 2 given indices
        while(start <= end){
            if(str[start] != str[end])
                return false;
            else{
                start++;
                end--;
            }
        }
        return true;
    }
    
    int pp2(string &s, vector<int>& dp, int pos){
        
        if(pos == s.size())
            return 0;
        
        if(dp[pos] != -1)
            return dp[pos];
        
        int minCount = INT_MAX;
        for(int j = pos ; j<s.size() ; j++){
            if(isPalin(s,pos,j)){
                int count = 1 + pp2(s,dp,j+1);
                minCount = min(count, minCount);
            }
        }
        dp[pos] = minCount;
        return dp[pos];
    }
        
    int minCut(string s) {
        
        int n = s.size();   
        
        if(n == 1 || isPalin(s,0,n-1))
            return 0;
        
        vector<int> dp(n,-1);
        int ans = pp2(s,dp,0) - 1;
        return ans;
    }
};
