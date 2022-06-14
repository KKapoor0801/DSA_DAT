class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        // DP SOLUTION - TC: O(n)
        int n = nums.size();
        int maxSum = nums[0];
        vector<int>dp_max_ending_here(n);
  
        dp_max_ending_here[0] = nums[0];
        
        for(int i = 1 ; i<n ; i++){
            dp_max_ending_here[i] = max(dp_max_ending_here[i-1] + nums[i], nums[i]);
            
            maxSum = max(maxSum, dp_max_ending_here[i]);
        }
        
        return maxSum;
        
        // KADANE's ALGORITHM SOLUTION - TC: O(3n) ---> O(n)
//         int fl = 0;
//         for(int i = 0 ; i<nums.size() ; i++){
//             if(nums[i] > 0){
//                 fl = 1;
//                 break;
//             }
//         }
//         // KADANE's ALGORITHM IF BOTH +ve & -ve NUMBERS ARE PRESENT
//         int maxSum = 0, currSum = 0;
//         if(fl == 1){
//             for(int i = 0 ; i<nums.size() ; i++){
//                 currSum += nums[i];
                
//                 if(currSum < 0){
//                     currSum = 0;
//                 }
//                 else{
//                     maxSum = max(maxSum, currSum);
//                 }
//             }
//         }
        
//         // KADANE's ALGORITHM IF ONLY -ve NUMBERS ARE PRESENT
//         else{
//             maxSum = INT_MIN;
//             for(int i = 0 ; i<nums.size() ; i++){
//                 currSum += nums[i];
//                 maxSum = max(maxSum, currSum);
//                 maxSum = max(maxSum, nums[i]);
//             }
//         }
        
//         return maxSum;
    }
};
