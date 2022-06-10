class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int,int> map;
        
        for(int i = 0 ; i<nums1.size() ; i++){
            map[nums1[i]]++;   // To store the count of each number in nums1
        }
        
        for(int i = 0 ; i<nums2.size() ; i++){
            
            // To check if number is present in nums2 and  its count > 0
            
            if(map.find(nums2[i]) != map.end() && map[nums2[i]] > 0){  
                res.push_back(nums2[i]);
                map[nums2[i]]--; // Decrement the count of number if it is used in the result.
            }
        }
        return res;
    }
};
