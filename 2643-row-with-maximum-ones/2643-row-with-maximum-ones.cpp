class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int cnt = 0, idx = 0;
        int maxi = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 1){
                    cnt++;
                    if(cnt > maxi){
                        maxi = cnt;
                        idx = i;
                    }
                }
            }
            cnt = 0;
        }
        return {idx, maxi};
    }
};