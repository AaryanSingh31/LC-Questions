class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int champ = -1;
        int maxi = 0;
        int cnt = 0;
        int n = grid.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j){
                    continue;
                }
                if(grid[i][j] == 1){
                    cnt++;
                    if(cnt > maxi){
                        maxi = cnt;
                        champ = i;
                    }
                }
            }
            cnt = 0;
        }
        return champ;
    }
};