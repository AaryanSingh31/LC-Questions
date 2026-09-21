class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int neighLive = 0;

                //8 neighours
                for(int di = -1; di <= 1; di++){
                    for(int dj = -1; dj <= 1; dj++){
                        if(di == 0 && dj == 0){
                            continue;
                        }
                        int ni = i+di;
                        int nj = j+dj;

                    if(ni >= 0 && ni < m && nj >= 0 && nj < n)
                        if(board[ni][nj] == 1 || board[ni][nj] == -1){
                            neighLive++;
                        }
                    }
                }
                if(board[i][j] == 1 && (neighLive < 2 || neighLive > 3)){
                    board[i][j] = -1;  //1->0
                }else if(neighLive == 3 && board[i][j] == 0){
                    board[i][j] = 2;   //0->1
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == -1) board[i][j] = 0;
                if(board[i][j] == 2) board[i][j] = 1;
            }
        }
    }
};