class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> diff(m, vector<int>(n, 0));
        vector<int> rowOnes(m, 0), colOnes(n, 0);
        for(int i = 0; i < m; i++){
            int rowO = 0;
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    rowO++;
                }
            }
            rowOnes[i] = rowO;
        }
        for(int j = 0; j < n; j++){
            int colO = 0;
            for(int i = 0; i < m; i++){
                if(grid[i][j] == 1){
                    colO++;
                }
            }
            colOnes[j] = colO;
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                grid[i][j] = rowOnes[i]+colOnes[j] - (m-rowOnes[i]) - (n-colOnes[j]);
            }
        }
        return grid;
    }
};