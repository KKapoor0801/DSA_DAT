class Solution {
public:
    string frequencySort(string s) {
        unordered_map<int,int> map;        
        for(int i = 0 ; i<s.size() ; i++){
            map[(int)s[i]]++ ;
        }
        
        vector<pair<int,int>> res(map.begin(),map.end()); //STORED THE MAP AS A VECTOR TO SORT
        
        // CUSTOM COMPARATOR IS USED
        sort(res.begin(),res.end(), [res](pair<int,int>&a , pair<int,int>&b){ 
            return a.second > b.second;
        });
        
        string ans = "";
        for(pair<int,int>p : res){
            for(int i = 0 ; i<p.second ; i++){
                ans += (char)p.first;
            }
        }
        return ans;
    }
};
