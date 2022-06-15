class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
//         // TC = O(nlogn)
        
//         int n = nums.size();
//         vector<int> res;
        
//         for(int i = 0 ; i<n ; i++){
            
//             auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
//             if(it == res.end())
//                 res.push_back(nums[i]);
//             else
//                 *it = nums[i];
//         }
        
//         return res.size();
        
        // TC = O(n^2)
        int n = nums.size();
        
        int maxLen = 1; // Even if 1 element is present then also the length would be at least 1
        
        vector<int>LIS_dp(n,1);
        // LIS_dp[i] =  stores the length of the subsequence ending at i  
        // by including all the j's less than that and forming a subsequence 
        
        for(int i = 1 ; i<n ; i++){
            
            for(int j = i-1 ; j>=0 ; j--){
                
                if(nums[j] < nums[i])
                    LIS_dp[i] = max(LIS_dp[i], 1 + LIS_dp[j]);
            }
            maxLen = max(maxLen, LIS_dp[i]);
        }
        return maxLen;
    }
};
