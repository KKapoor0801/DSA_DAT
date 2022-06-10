class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end()); // IMPORTANT STEP TO SORT ON THE BASIS OF START TIME
        
        if(intervals.size() == 0){
            return {{}};
        }
        
        int start = intervals[0][0];
        int end = intervals[0][1];
                
        vector<vector<int>> res;
        
        for(int i = 1; i<intervals.size() ; i++){
            if(end >= intervals[i][0]){
                end = max(end, intervals[i][1]);
            }
            else{
                res.push_back({start,end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        res.push_back({start,end});  // IMPORTANT TO ADD THE CONTRIBUTION OF THE LAST {START,END} TO RESULT
        return res;
    }
};
