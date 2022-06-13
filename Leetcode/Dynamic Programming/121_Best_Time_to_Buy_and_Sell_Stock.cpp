class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int rightMostElt = prices[prices.size() - 1];
        
        int maxP = 0;
        
        for(int i = prices.size() - 2; i>=0 ; i--){
            if(prices[i] > rightMostElt){
                rightMostElt = prices[i];
            }
            else{
                maxP = max(maxP, rightMostElt - prices[i]);
            }
        }
        
        return maxP;
    }
};
