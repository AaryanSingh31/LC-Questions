class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int m = grid.size(); //row size
        int n = grid[0].size(); //col size

        for(int i = 0; i < m; i++){
            sort(grid[i].begin(), grid[i].end()); //row wise sorting
        }
        int ans = 0;

//loop for col to row and not from row to col
        for(int j = 0; j < n; j++){
            int maxEl = 0;

            for(int i = 0; i < m; i++){
                maxEl = max(maxEl, grid[i][j]); //max el of each col
            }
            ans += maxEl; //add it to the ans after evry end of the row visit cuz that is the 1 col visit
        }
        return ans;
    }
};