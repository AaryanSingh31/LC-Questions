class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;
        int n = mat.size();
        for(int i = 0; i < mat.size(); i++){
            sum += mat[i][i] + mat[i][n-1-i];
        }
        return n % 2 == 0 ? sum : sum - mat[n/2][n/2];
    }
};