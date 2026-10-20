class Solution {
public:
    vector<vector<string>> ans;
    bool isUp(vector<string> &board, int row, int col){
        for(int i = row-1; i >= 0; i--){
            if(board[i][col] == 'Q'){
                return false;
            }
        }
        return true;
    }
    bool isLeftUp(vector<string> &board, int row, int col){
        row--, col--;
        while(row >= 0 && col >= 0){
            if(board[row][col] == 'Q') return false;
            row--, col--;
        }
        return true;
    }
    bool isRightUp(vector<string> &board, int row, int col){
        row--, col++;
        while(row >= 0 && col < board.size()){
            if(board[row][col] == 'Q') return false;
            row--, col++;
        }
        return true;
    }

    bool isValid(vector<string> &board, int row, int col){
        if(isUp(board, row, col) && isLeftUp(board, row, col) && isRightUp(board, row, col)){
            return true;
        }
        return false;
    }

    void solve(vector<string> &board, int row){
        if(row >= board.size()){
            ans.push_back(board);
            return;
        }

        for(int col = 0; col < board[0].size(); col++){
            if(isValid(board, row, col)){
                board[row][col] = 'Q';
                solve(board, row+1);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        int row = 0;
        solve(board, row);

        return ans;
    }
};