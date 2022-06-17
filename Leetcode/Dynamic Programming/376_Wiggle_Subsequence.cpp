class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        
        // TC = O(n)
        
        // THE SOLUTION IS A SLIGHT TWEAK FROM TURBULENT SUBARRAY QUESTION
        
        int n = nums.size();
        if(n == 1)
            return 1;
        
        vector<int>dp_pos(n,1);
        vector<int>dp_neg(n,1);
        
        int maxLen = 1;
        
        for(int i = 1 ; i<n ; i++){
            
            if(nums[i] > nums[i-1]){
                dp_pos[i] += dp_neg[i-1];
                dp_neg[i] = dp_neg[i-1];
            }
            
            if(nums[i] < nums[i-1]){
                dp_neg[i] += dp_pos[i-1];
                dp_pos[i] = dp_pos[i-1];
            }
            
            if(nums[i] == nums[i-1]){
                dp_pos[i] = dp_pos[i-1];
                dp_neg[i] = dp_neg[i-1];
            }
        
        }
        
        // We use (n-1)th element for maxLen because the last elements of these vectors store the final lengths of the positive diff & 
        // negative diff wiggle subsequences
        
        maxLen = max(dp_pos[n-1], dp_neg[n-1]);
        return maxLen;
    }
};
