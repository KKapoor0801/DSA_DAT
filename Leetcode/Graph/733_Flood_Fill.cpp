class Solution {
public:
    
    void fill(vector<vector<int>>& image, int sr, int sc, int m, int n, int color, int initial_color){
        
        if(sr < 0 || sc < 0 || sr >= m || sc >= n)
            return;
        
        if(image[sr][sc] != initial_color)
            return;
        
        image[sr][sc] = color;
        
        fill(image,sr+1,sc,m,n,color,initial_color);
        fill(image,sr-1,sc,m,n,color,initial_color);
        fill(image,sr,sc+1,m,n,color,initial_color);
        fill(image,sr,sc-1,m,n,color,initial_color);
        
        return;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int m = image.size();
        int n = image[0].size();
        
        int initial_color = image[sr][sc];
        if(initial_color == color)   // V.V.V.IMP CORNER CASE - [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0
            return image;
        
        fill(image,sr,sc,m,n,color,initial_color);
        return image;
    }
};
