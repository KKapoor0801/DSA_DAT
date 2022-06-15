class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        
        int n = arr.size();
        
        vector<int> decrement_dp(n,1);
        vector<int> increment_dp(n,1);
        
        int currLen = 1;
        int maxLen = 1;
        
        for(int i = 1 ; i<n ; i++){
            
            if(arr[i] > arr[i-1])
                increment_dp[i] = decrement_dp[i-1] + 1;
            
            if(arr[i] < arr[i-1])
                decrement_dp[i] = increment_dp[i-1] + 1;
            
            currLen = max(increment_dp[i], decrement_dp[i]);
            maxLen = max(maxLen, currLen);
            
        }
        return maxLen;
    }
};
