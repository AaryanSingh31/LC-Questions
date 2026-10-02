class Solution {
public:

    bool isMagic(vector<vector<int>>& grid, int r, int c){
        //uniqueness check
        unordered_set<int> st;
        for(int i = r; i < r+3; i++){
            for(int j = c; j < c+3; j++){
                if(grid[i][j] < 1 || grid[i][j] > 9 || st.count(grid[i][j])){
                    return false;
                }else {
                    st.insert(grid[i][j]);
                }
            }
        }

        //Sums check
        int SUM = grid[r][c]+grid[r][c+1]+grid[r][c+2];

        //rowSum check 
        for(int i = r; i < r+3; i++){
            int rs = grid[i][c]+grid[i][c+1]+grid[i][c+2];

            if(rs != SUM) return false;
            rs = 0;
        }
        //col sum check
        for(int j = c; j < c+3; j++){
            int cs = grid[r][j]+grid[r+1][j]+grid[r+2][j];

            if(cs != SUM) return false;
            cs = 0;
        }
        //diag sum check
        int d1 = 0, d2 = 0;
        for(int k = 0; k < 3; k++){
            d1 += grid[r+k][c+k]; 
            d2 += grid[r+k][c+2-k];
        }
        if(d1 != SUM) return false;
        if(d2 != SUM) return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int cnt = 0;
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i <= m-3; i++){
            for(int j = 0; j <= n-3; j++){
                if(isMagic(grid, i, j)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};