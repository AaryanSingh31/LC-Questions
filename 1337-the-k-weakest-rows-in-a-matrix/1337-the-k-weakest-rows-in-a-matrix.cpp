class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<pair<int, int>> mp;
        for(int i = 0; i < m; i++){
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 1){
                    cnt++;
                }
            }
            mp.emplace_back(cnt, i);
        }
        vector<int> ans;
        sort(mp.begin(), mp.end());
        for(int i = 0; i < k; i++){
            ans.push_back(mp[i].second);
        }
        return ans;
    }
};