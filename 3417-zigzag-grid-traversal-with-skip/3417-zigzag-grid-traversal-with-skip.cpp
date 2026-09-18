class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        vector<int> ans;
        int m = grid.size();
        int n = grid[0].size();
        bool fromL = true;
        for(int i = 0; i < m; i++){
            if(fromL){
                for(int j = 0; j < n; j+=2){
                    ans.push_back(grid[i][j]);
                }
            }else {
                if(n%2 == 1){
                    for(int j = n-2; j >= 0; j-=2){
                        ans.push_back(grid[i][j]);
                    }
                }else {
                    for(int j = n-1; j >= 0; j-=2){
                        ans.push_back(grid[i][j]);
                    }
                }
            }
            fromL = !fromL;
        }
        return ans;
    }
};