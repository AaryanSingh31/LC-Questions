class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<bool> foundRow(n+1, false);
        vector<bool> foundCol(n+1, false);

        //CHECK EVERY ROW

        for(int i = 0; i < n; i++){
            //reset the row vector to false again for next row

            fill(foundRow.begin(), foundRow.end(), false);
            for(int j = 0; j < n; j++){
                int num = matrix[i][j];
                foundRow[num] = true;
            }
            for(int k = 1; k < foundRow.size(); k++){
                if(foundRow[k] == false){
                    return false;
                }
            }
        }

        //CHECK EVERY COL

        for(int j = 0; j < n; j++){
            //Reset the foundCol to false for next col
            fill(foundCol.begin(), foundCol.end(), false);

            for(int i = 0; i < n; i++){
                int num = matrix[i][j];
                foundCol[num] = true;
            }
            for(int k = 1; k < foundCol.size(); k++){
                if(foundCol[k] == false){
                    return false;
                }
            }
        }
        return true;     
    }
};