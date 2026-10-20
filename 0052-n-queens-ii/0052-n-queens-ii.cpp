class Solution {
public:
    int ans;
    unordered_set<int> up, upleftDiag,upRightDiag;

    int solve(vector<string> &board, int row, int &cnt){
        if(row == board.size()){
            return cnt++;
        }
        for(int col = 0; col < board[0].size(); col++){
            int upDir = col;
            int leftDiag = row+col;
            int antiLDiag = row-col;

            if(up.find(upDir) == up.end() && upleftDiag.find(leftDiag) == upleftDiag.end() && upRightDiag.find(antiLDiag) == upRightDiag.end()){
                up.insert(upDir);
                upleftDiag.insert(leftDiag);
                upRightDiag.insert(antiLDiag);
                
                board[row][col] = 'Q';
                solve(board, row+1, cnt);

                up.erase(upDir);
                upleftDiag.erase(leftDiag);
                upRightDiag.erase(antiLDiag);
                
                board[row][col] = '.';

            }
        }
        return cnt;
    }
    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        int row = 0, cnt = 0;
        solve(board, row, cnt);
        return cnt;
    }
};