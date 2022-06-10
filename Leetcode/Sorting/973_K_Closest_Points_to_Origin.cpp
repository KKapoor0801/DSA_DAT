class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        int n = points.size();
        int d;
        vector<pair<int,int>> arrange;
        
        vector<vector<int>> res;
        
        for(int i = 0 ; i<n ; i++){
            d = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            arrange.push_back({d,i});
        }
        
        sort(arrange.begin(), arrange.end());
        
        for(pair<int,int>p : arrange){
            if(k>0){
            res.push_back(points[p.second]);
            k--;
        }
        }
        return res;
    }
};
