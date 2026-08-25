class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        //we'll check for 4 rotations 90 -> 180 -> 270 -> 360
        for(int k = 0; k < 4; k++){
            //if any of the rotations become equal to target return true
            if(mat == target){
                return true;
            }
            vector<vector<int>> temp(n, vector<int>(n)); //temp vector for storing rotations
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    temp[j][n-i-1] = mat[i][j];
                }
            }
            mat = temp; //convert the mat to the new rotated matrix for checking or for further rotations
        }
        return false;
    }
};