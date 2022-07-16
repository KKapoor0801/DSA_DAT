class Solution {
public:
    
    bool detectCycle(vector<bool>& visited, vector<bool>& currVisited, int source, vector<int>adj[]){
        visited[source] = true;
        currVisited[source] = true;
        
        vector<int>data = adj[source];
        for(auto x : data){
            if(visited[x] == false){
                if(detectCycle(visited,currVisited,x,adj)){
                    return 1;
                }
            }
            else if(visited[x] == true && currVisited[x] == true){
                return 1;
            }
        }
        
        currVisited[source] = false;
        return 0;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        
        vector<int>adj[n];
        for(auto x : prerequisites){
            vector<int>data = x;
            int a = data[0];
            int b = data[1];
            adj[a].push_back(b);
        }
        
        vector<bool>visited(n,false);
        vector<bool>currVisited(n,false);
        
        for(int i = 0 ; i<n ; i++){
            if(visited[i] == false){
                if(detectCycle(visited, currVisited, i, adj))
                    return 0;
            }
        }
        return 1;
    }
};
