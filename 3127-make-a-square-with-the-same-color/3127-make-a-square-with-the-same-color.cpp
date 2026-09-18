class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        int wBlock = 0, bBlock = 0;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                if(grid[i][j] == 'W') wBlock++;
                else bBlock++;
            }
        }
        if(bBlock != wBlock) return true;
        wBlock = 0, bBlock = 0;
        for(int i = 0; i < 2; i++){
            for(int j = 1; j <= 2; j++){
                if(grid[i][j] == 'W') wBlock++;
                else bBlock++;
            }
        }
        if(bBlock != wBlock) return true;
        wBlock = 0, bBlock = 0;

        for(int i = 1; i <= 2; i++){
            for(int j = 0; j < 2; j++){
                if(grid[i][j] == 'W') wBlock++;
                else bBlock++;
            }
        }
        if(bBlock != wBlock) return true;
        wBlock = 0, bBlock = 0;

        for(int i = 1; i <= 2; i++){
            for(int j = 1; j <= 2; j++){
                if(grid[i][j] == 'W') wBlock++;
                else bBlock++;
            }
        }
        if(bBlock != wBlock) return true;
        return false;
    }
};