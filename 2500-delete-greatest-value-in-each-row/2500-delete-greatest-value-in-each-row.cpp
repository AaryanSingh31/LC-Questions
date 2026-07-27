class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int m = grid.size(); //row size
        int n = grid[0].size(); //col size

        for(int i = 0; i < m; i++){
            sort(grid[i].begin(), grid[i].end());
        }
        int ans = 0;

        for(int j = 0; j < n; j++){
            int maxEl = 0;

            for(int i = 0; i < m; i++){
                maxEl = max(maxEl, grid[i][j]);
            }
            ans += maxEl;
        }
        return ans;
    }
};