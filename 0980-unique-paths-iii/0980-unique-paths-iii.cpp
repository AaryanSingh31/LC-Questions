class Solution {
public:
    int m, n;
    vector<vector<int>> dirn{
        {0,1}, 
        {0,-1},
        {1,0}, 
        {-1,0}
    };
    int dfs(vector<vector<int>>& grid, int i, int j, int rem){
        int cnt = 0;
        
        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == -1){
           return 0;
        }

        if(grid[i][j] == 2)  return rem == 1 ? 1 : 0;;
        int temp = grid[i][j];
        grid[i][j] = -1;

        for(auto &it : dirn){
            int n_i = i + it[0];
            int n_j = j + it[1];
            if(n_i >= 0 && n_i < m && n_j >= 0 && n_j < n) cnt += dfs(grid, n_i, n_j, rem-1);
        }
        grid[i][j] = temp;
        return cnt;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int ans = 0;
        int p = 0;
        int rem = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == -1){
                    p++;
                }
            }
        }
        rem = m*n - p;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    ans = dfs(grid, i, j, rem);
                }
            }
        }
        return ans;
    }
};