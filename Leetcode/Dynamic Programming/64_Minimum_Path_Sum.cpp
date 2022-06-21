class Solution {
public:
    int minSum(vector<vector<int>>& grid, int m, int n, int i, int j, vector<vector<int>>& dp){
        
        if(i == m-1 && j == n-1)
            return grid[m-1][n-1];
        
        if(i>=m || j>=n)
            return 1e5;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int down = minSum(grid,m,n,i+1,j,dp);
        int right = minSum(grid,m,n,i,j+1,dp);
        
        dp[i][j] = grid[i][j] + min(down,right);
        
        return dp[i][j];
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>>dp(m,vector<int>(n,-1));
        
        return minSum(grid,m,n,0,0,dp);
    }
};
