class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        //checkinf if the rows are different or not
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n-1; j++){
                if(grid[i][j] == grid[i][j+1]) return false;
            }
        }
        //checking if the col are same or not
        for(int j = 0; j < n; j++){
            for(int i = 0; i < m-1; i++){
                if(grid[i][j] != grid[i+1][j]) return false;
            }
        }
        return true;
    }
};