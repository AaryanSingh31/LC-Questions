class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int maxRows = 0;

        for(auto &curRow : matrix){
            vector<int> inv(n);

            //Inverting the curRow and storing it to the inv
            for(int col = 0; col < n; col++){
                inv[col] = curRow[col] == 0 ? 1 : 0; //flip the val
            }
            int cnt = 0;
            //check if the rows are equal to currentRow or invertedto currRow
            for(auto &row : matrix){
                if(row == curRow || row == inv){
                    cnt++;
                }
            }
            maxRows = max(maxRows, cnt);
        }
        return maxRows;
    }
};