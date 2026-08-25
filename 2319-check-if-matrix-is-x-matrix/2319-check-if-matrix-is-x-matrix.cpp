class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& matrix) {
        
        int n = matrix.size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] != 0 && i != j && j != n-i-1){
                    return false;
                }
                if(matrix[i][i] == 0){
                    return false;
                }
                if(matrix[i][n-i-1] == 0){
                    return false;
                }
            }
        }
        return true;
    }
};