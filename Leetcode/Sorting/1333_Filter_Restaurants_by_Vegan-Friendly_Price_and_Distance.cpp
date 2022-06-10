class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        
        int n = restaurants.size();
        vector<int> res;
        
        vector<pair<int,int>> arrange;
        
        for(int i = 0 ; i<n ; i++){
            
            if(veganFriendly == 0){
                if(restaurants[i][3] <= maxPrice 
                    && restaurants[i][4] <= maxDistance){
                    
                arrange.push_back({restaurants[i][1], restaurants[i][0]});
            }
        }
            
          else if(restaurants[i][2] == veganFriendly 
               && restaurants[i][3] <= maxPrice 
               && restaurants[i][4] <= maxDistance){
                
               arrange.push_back({restaurants[i][1], restaurants[i][0]});
            }
        }
        
        if(arrange.size() == 0) return {};
                
        sort(arrange.begin(), arrange.end(),[arrange](pair<int,int>&a, pair<int,int>&b){
            if (a.first == b.first) 
                return (a.second > b.second);
            else 
                return (a.first > b.first);
        });
        
        for(int i = 0 ; i<arrange.size() ; i++){
            res.push_back(arrange[i].second);
        }
        
        return res;
    }
};
