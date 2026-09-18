class NeighborSum {
public:
    vector<vector<int>> grid;
    NeighborSum(vector<vector<int>>& grid) {
        this->grid = grid;
    }
    
    int adjacentSum(int val) {
        int n = grid.size();
        int top = 0, right = 0, bottom = 0, left = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == val){
                    if(i != 0) top = grid[i-1][j];
                    if(j != 0) left = grid[i][j-1];
                    if(i != n-1) bottom = grid[i+1][j];
                    if(j != n-1) right = grid[i][j+1];
                }
            }
        }
        return (top+left+bottom+right);
    }
    
    int diagonalSum(int val) {
        int topL = 0, topR = 0, bottomL = 0, bottomR = 0;
        int n = grid.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == val){
                    if(i != 0 && j != 0) topL = grid[i-1][j-1];
                    if(i != 0 && j != n-1) topR = grid[i-1][j+1];
                    if(i != n-1 && j != 0) bottomL = grid[i+1][j-1];
                    if(i != n-1 && j != n-1) bottomR = grid[i+1][j+1];
                }
            }
        }
        return (topL+topR+bottomL+bottomR);
    }
};

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum* obj = new NeighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */