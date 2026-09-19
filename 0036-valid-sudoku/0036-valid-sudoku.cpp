class Solution {
public:
    bool validBox(vector<vector<char>> &board, int sR, int endR, int sC, int endC){
        unordered_set<char> st;
        for(int i = sR; i <= endR; i++){
            for(int j = sC; j <= endC; j++){
                if(board[i][j] == '.') continue;
                if(st.find(board[i][j]) != st.end()) return false;

                st.insert(board[i][j]);
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        //checking rows
        for(int i = 0; i < 9; i++){
            unordered_set<char> st;
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.') continue;
                
                if(st.find(board[i][j]) != st.end()){
                    return false;
                }
                st.insert(board[i][j]);
            }
        }
        //checking cols
        for(int j = 0; j < 9; j++){
            unordered_set<char> st;
            for(int i = 0; i < 9; i++){
                if(board[i][j] == '.') continue;
                
                if(st.find(board[i][j]) != st.end()){
                    return false;
                }
                st.insert(board[i][j]);
            }
        }

        //checking 3x3 box
        for(int sR = 0; sR < 9; sR+=3){
           int endR = sR+2;
           for(int sC = 0; sC < 9; sC += 3){
                int endC = sC+2;

                if(!validBox(board, sR, endR, sC, endC)){
                    return false;
                }
            }
        }
        return true;
    }
};