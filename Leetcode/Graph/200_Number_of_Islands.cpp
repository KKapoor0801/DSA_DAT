class Solution {
public:
    
    void countIslands(vector<vector<char>>& grid, int i, int j, int m, int n){
        
        if(i<0 || j<0 || i>=m || j>=n)  // Even the surrounding boundaries are considered as water
            return;
        
        if(grid[i][j] == '0')
            return;
        
        grid[i][j] = '0';  // Marking the land as '0' after visiting it
        
        // Trying all possible combinations in all 4 directions to find a land 
        countIslands(grid,i+1,j,m,n);
        countIslands(grid,i-1,j,m,n);
        countIslands(grid,i,j+1,m,n);
        countIslands(grid,i,j-1,m,n);
        
        return;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int count = 0;
        
        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                if(grid[i][j] == '1'){
                    countIslands(grid,i,j,m,n);
                    count++;
                }
            }
        }
        
        return count;
    }
};
