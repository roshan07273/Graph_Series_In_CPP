class Solution {
private:
    void dfs(
        int row , 
        int col ,
        vector<vector<int>>& image, 
        vector<vector<int>>& ans , 
        int color , 
        int iniColor , 
        int delRow[] , 
        int delCol[] , 
        int n , 
        int m)
    {
        ans[row][col] = color;
        for(int i = 0 ; i < 4 ; i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == iniColor && ans[nrow][ncol] != color){
                dfs(nrow , ncol , image , ans , color , iniColor , delRow , delCol , n , m);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size(); 
        vector<vector<int>>& ans = image;
        int iniColor = image[sr][sc];
        int delRow[] = {-1 , 0 , +1 , 0};
        int delCol[] = {0 , +1 , 0 , -1};
        dfs(sr , sc , image , ans , color , iniColor , delRow , delCol , n , m);
        return ans;
    }
};
