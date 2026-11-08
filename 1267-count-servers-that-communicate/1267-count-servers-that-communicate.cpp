class Solution {
public:
    bool isPresent(int row, int col, vector<vector<int>>& grid){
        int m = grid.size(), n = grid[0].size();
        bool rP = false, cP = false;
        for(int i = 0; i < m; i++){
            if(i == row) continue;
            if(grid[i][col] == 1){
                rP = true;
                break;
            }
        }
        for(int j = 0; j < n; j++){
            if(j == col) continue;
            if(grid[row][j] == 1){
                cP = true;
                break;
            }
        }
        if(rP || cP){
            return true;
        }
        return false;
    }
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int cnt = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && isPresent(i, j, grid)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};