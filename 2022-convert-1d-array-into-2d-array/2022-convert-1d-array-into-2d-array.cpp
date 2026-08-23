class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& org, int m, int n) {
        vector<vector<int>> empty;
        vector<vector<int>> ans(m, vector<int>(n));
        if(org.size() != m * n){
            return empty;
        }
        int r1 = 0,  c1 = 0;
        for(int i = 0; i < org.size(); i++){
            ans[r1][c1] = org[i];
            c1++;
            if(c1 == n){
                r1++;
                c1 = 0;
            }
        }
        return ans;
    }
};