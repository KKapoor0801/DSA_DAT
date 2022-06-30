class Solution {
public:
    
    // BOUNDARY DFS TYPE OF QUESTION
    
    void countClosed(vector<vector<int>>& grid, int i , int j, int m, int n){
        
        if(i < 0 || j < 0 || i >= m || j >= n)
            return;
        
        if(grid[i][j] == 1)
            return;
        
        if(grid[i][j] == -1)   // This is to check the visited 0 on the boundary
            return;
        
        grid[i][j] = -1;  // This is to mark the visited 0 on the boundary. We can also keep it to 1 by removing the above if condition of -1.
        
        countClosed(grid,i+1,j,m,n);
        countClosed(grid,i-1,j,m,n);
        countClosed(grid,i,j+1,m,n);
        countClosed(grid,i,j-1,m,n);
        
        return;
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int count = 0;
        
        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                if(i == 0 || j == 0 || i == m-1 || j == n-1){
                    countClosed(grid,i,j,m,n);  // Boundary DFS 
                }
            }
        }
        
        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                if(grid[i][j] == 0){
                    countClosed(grid,i,j,m,n);  // Non Boundary DFS to check the closed islands
                    count++;
                }
            }
        }
        
        return count;
    }
};
