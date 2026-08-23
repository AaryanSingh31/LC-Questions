class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& org, int m, int n) {
        vector<vector<int>> empty;
        vector<vector<int>> ans(m, vector<int>(n));
        if(org.size() != m * n){
            return empty;
        }
        for(int i = 0; i < org.size(); i++){
            ans[i/n][i%n] = org[i];
        }
        return ans;
    }
};