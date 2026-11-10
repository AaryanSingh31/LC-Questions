class Solution {
public:
    int m,n;
    vector<vector<int>> dirn{
        {0,1}, 
        {0,-1}, 
        {1, 0}, 
        {-1,0}};

bool find(int idx, int i, int j, vector<vector<char>>& board, string word){
    if(idx == word.length()) return true;
    if(i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '$') return false;
    if(board[i][j] != word[idx]) return false;

    char temp;
    temp = board[i][j];
    board[i][j] = '$';
    for(auto &it : dirn){
        int n_i = i+it[0];
        int n_j = j+it[1];

        if(find(idx+1, n_i, n_j, board, word)){
            return true;
        }
    }
    board[i][j] = temp;
    return false;
}

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size();
        int idx = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(word[0] == board[i][j] && find(0, i, j, board, word)){
                    return true;
                }
            }
        }
        return false;
    }
};