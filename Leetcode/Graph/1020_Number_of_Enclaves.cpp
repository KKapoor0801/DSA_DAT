class Solution {
public:
    
    void countMoves(vector<vector<int>>& grid, int i, int j, int m, int n){
        
        if(i < 0 || j < 0 || i >= m || j >= n)
            return;
        
        if(grid[i][j] == 0)
            return;
        
        if(grid[i][j] == -1)
            return;
        
        if(grid[i][j] == 1)
            grid[i][j] = -1;
        
        countMoves(grid,i+1,j,m,n);
        countMoves(grid,i-1,j,m,n);
        countMoves(grid,i,j+1,m,n);
        countMoves(grid,i,j-1,m,n);
        
        return;
        
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int count = 0;
        
        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                if(i == 0 || j == 0 || i == m-1 || j == n-1){
                    countMoves(grid,i,j,m,n);
                }
            }
        }
        
        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                if(grid[i][j] == 1)
                    count++;
            }
        }
        
        return count;
    }
};
