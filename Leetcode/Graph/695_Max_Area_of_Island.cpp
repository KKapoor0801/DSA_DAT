class Solution {
public:
    // DFS TRAVERSAL
    void calcArea(vector<vector<int>>& grid, int i, int j, int m, int n, int& area){
        
        if(i < 0 || j < 0 || i >= m || j >= n)
            return;
        
        if(grid[i][j] == 0)
            return;
        
        grid[i][j] = 0;
        area++;
        
        calcArea(grid,i+1,j,m,n,area);
        calcArea(grid,i-1,j,m,n,area);
        calcArea(grid,i,j+1,m,n,area);
        calcArea(grid,i,j-1,m,n,area);
        
        return;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        int maxArea = 0;
        
        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                if(grid[i][j] == 1){
                    
                    int currArea = 0;
                    calcArea(grid,i,j,m,n,currArea);
                    maxArea = max(maxArea, currArea);
                    
                }
            }
        }
        return maxArea;
    }
};
