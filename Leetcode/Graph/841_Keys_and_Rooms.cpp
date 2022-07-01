class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        // BFS TRAVERSAL
        
        queue<int>q;
        int n = rooms[0].size();
        
        for(int i = 0 ; i<n ; i++){
            q.push(rooms[0][i]);
        }
        
        vector<bool>visited(rooms.size(), false); // to mark which room has been visited
        
        visited[0] = true;  // because room 0 is open
        
        while(q.empty() == false){  // can also be like != true
            
            int currKey = q.front();  // it stores the current Key which has been pushed into the queue
            
        // Optimization to avoid checking the same room if we have already visited but got its key again in some other room. eg: test case 2 - we got the key for room 3 in both room 0 and room 1.
            if(visited[currKey] == false){
                
                int N = rooms[currKey].size();
                for(int i = 0 ; i<N ; i++){
                    if(visited[rooms[currKey][i]] == false)
                        q.push(rooms[currKey][i]);
                }
            
                visited[currKey] = true;
            }
                
            q.pop();  //it will pop out the currKey as room associated with that currKey has now been visited
            
        }
        
        for(int i = 0 ; i<visited.size() ; i++){
            if(visited[i] == false) 
                return false;
        }
        return true;
    }
};
