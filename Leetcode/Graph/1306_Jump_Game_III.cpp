class Solution {
public:
    
    // DFS TRAVERSAL ---> RECURSION
    
    bool ans = false;
    bool jump(vector<int>& arr, int start, int n, vector<bool>visited){
        
        if(start < 0 || start >= n)
            return false;
        
        if(arr[start] == 0)
            return true;
        
        if(visited[start] == true)
            return false;
        
        visited[start] = true;
        ans = jump(arr,start+arr[start],n,visited) || jump(arr,start-arr[start],n,visited);
        return ans;
        
    }
    
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        
        vector<bool>visited(n,false);  // TO MARK THE INDEX WHICH HAS BEEN VISITED BY US
        return jump(arr,start,n,visited);
    }
};
