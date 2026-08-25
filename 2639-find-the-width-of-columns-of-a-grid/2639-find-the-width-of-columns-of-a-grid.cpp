class Solution {
public:
    int count(int n){
        int cnt = 0;
        if(n < 0) {
            cnt++;
            n = -n;
        }    
        while(n>0){
            cnt++;
            n/=10;
        }
        return cnt;
    }
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(m == 1 && n == 1) return {1};
        vector<int> ans;
        for(int j = 0; j < n; j++){
            int maxi = 1;
            for(int i = 0; i < m; i++){
                maxi = max(maxi, count(grid[i][j]));
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};