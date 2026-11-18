class Solution {
public:
    vector<vector<int>> dirn{
        {1,0},
        {0,1},
        {0,-1},
        {-1,0}
    };

    void dfs(int i, int j, int &maxVal, int val, vector<vector<int>> &grid, int m, int n){
        val += grid[i][j];
        maxVal = max(maxVal, val);
            int temp = grid[i][j];
            grid[i][j] = 0;

            for(auto &it : dirn){
                int n_i = i + it[0];
                int n_j = j + it[1];
                if(n_i >= 0 && n_i < m && n_j >= 0 && n_j < n && grid[n_i][n_j] != 0){
                    
                    dfs(n_i, n_j, maxVal, val, grid, m , n);
                }
            }
    
            grid[i][j] = temp;
        }
    int getMaximumGold(vector<vector<int>>& grid) {
        int maxVal = 0;
        int m = grid.size(),  n = grid[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] != 0){
                    dfs(i, j, maxVal, 0, grid, m, n);
                    // grid[i][j] = 0;
                }
            }
        }
        return maxVal;
    }
};