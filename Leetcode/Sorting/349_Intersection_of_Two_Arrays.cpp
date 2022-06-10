class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        set<int> s;
        vector<int> res;
        
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
                if(nums2[j] == nums1[i])
                    s.insert(nums1[i]);
                }
            }
        set<int>::iterator it;
        
        for(it = s.begin() ; it != s.end() ; it++){
            res.push_back(*it);
        }
        
        return res;
        }
};
