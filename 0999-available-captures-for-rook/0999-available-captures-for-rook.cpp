class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int cnt = 0;
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if(board[i][j] == 'R'){
                    for(int k = i-1; k >= 0; k--){
                        if(board[k][j] == 'B') break;
                        if(board[k][j] == 'p'){
                            cnt++;
                            break;
                        }
                    }
                    for(int l = i+1; l < 8; l++){
                        if(board[l][j] == 'B') break;
                        if(board[l][j] == 'p') {
                            cnt++;
                            break;
                        }
                    }
                    for(int m = j-1; m >= 0; m--){
                        if(board[i][m] == 'B') break;
                        if(board[i][m] == 'p') {
                            cnt++;
                            break;
                        }
                    }
                    for(int n = j+1; n < 8; n++){
                        if(board[i][n] == 'B') break;
                        if(board[i][n] == 'p'){
                            cnt++;
                            break;
                        }
                    }
                }
            }
        }
        return cnt;
    }
};