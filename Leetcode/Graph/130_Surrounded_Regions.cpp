class Solution {
public:
    
    void capture(vector<vector<char>>& board, int i, int j, int m, int n){
        
        if(i < 0 || j < 0 || i >= m || j >= n)
            return;
        
        if(board[i][j] == 'X')
            return;
        
        if(board[i][j] == 'B')
            return;
        
        if(board[i][j] == 'O'){
            board[i][j] = 'B';
        }
                
        capture(board,i+1,j,m,n);
        capture(board,i-1,j,m,n);
        capture(board,i,j+1,m,n);
        capture(board,i,j-1,m,n);
        
        return;
    }
    
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                if(i == 0 || j == 0 || i== m-1 || j == n-1){
                    capture(board,i,j,m,n);
                }
            }
        }
        
        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                
                else if(board[i][j] == 'B')
                    board[i][j] = 'O';
            }
        }
        
    }
};
