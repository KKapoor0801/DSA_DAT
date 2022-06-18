class Solution {
public:
    
    // SIMILAR TO LEETCODE 416 --> PARTITION EQUAL SUBSET SUM
    
    // This ques is basically a variation of 0/1 Knapsack --> We have to minimise the difference between 2 subsets and try to get that min diff
    
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size(), totalSum = 0;
        //int totalSum = accumulate(stones.begin(), stones.end(), totalSum);
        
        for(int i = 0 ; i<n ; i++)
            totalSum += stones[i];
            
        if(n == 1)
            return stones[0];
        
        int subset_sum = totalSum/2; // We try to make the subset_sum reach total/2 for having a difference of 0 ---> minimum possible difference 
        int maxSubsetSum = 0;
        
        vector<vector<int>>dp_count(n+1, vector<int>(subset_sum+1,0));
        
        for(int i = 0 ; i<n+1 ; i++)
            dp_count[i][0] = 1;
        
        for(int i = 1 ; i<n+1 ; i++){
            
            for(int j = 0 ; j<subset_sum+1 ; j++){
                
                if(stones[i-1] > j)
                    dp_count[i][j] = dp_count[i-1][j];
                else
                    dp_count[i][j] = dp_count[i-1][j-stones[i-1]] + dp_count[i-1][j];

                if(dp_count[i][j] != 0)
                    maxSubsetSum = max(maxSubsetSum, j); //We try to get the maxSum possible until total/2
            }
            
        }
        
        int second_subset_sum = totalSum - maxSubsetSum; //Max sum of the other subset after subtracting the max possible sum from the former subset.
        return (abs(second_subset_sum - maxSubsetSum)); // Min possible difference between the 2 stones
    }
};
