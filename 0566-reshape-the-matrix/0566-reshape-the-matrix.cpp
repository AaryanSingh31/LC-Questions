class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>> ans(r, vector<int>(c));
        int m = mat.size(), n = mat[0].size();
        if(r*c != m*n){
            return mat;
        }

        int c1 = 0, r1 = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                ans[r1][c1] = mat[i][j];
                    c1++;
                    if(c1 == c){
                        r1++;
                        c1 = 0;
                    }
            }
        }
        return ans;
    }
};