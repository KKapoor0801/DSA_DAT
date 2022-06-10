class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        int prev = 0;
        int count = 0;
        
        for(int curr = 1 ; curr<intervals.size() ; curr++){
            
            // [1,5] [3,6] ---> CASE 1 - a part is overlapping so its better to delete the 2nd term,i.e., [3,6]
            
            // [1,5] [2,3] ---> CASE 2 - full overlap so its better to delete the 1st term,i.e., [1,5]
            
            // [1,2] [2,3] ---> CASE 3 - No Overlap
            
            if(intervals[curr][0] < intervals[prev][1]){
                
                count++; // Deletion has to be performed in this
                
            if(intervals[curr][1] <= intervals[prev][1]){
                    prev = curr;
            }
        }
            else{
                prev = curr;
            }
            
        }
        
        return count;
    }
};
