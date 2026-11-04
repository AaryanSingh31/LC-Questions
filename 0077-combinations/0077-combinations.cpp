class Solution {
public:
    void solve(int n, vector<int> &temp, vector<vector<int>> &ans, int i, int k){
        if(temp.size() == k){
            ans.push_back(temp);
            return;
        }
        if(i > n || temp.size() == n){
            return;
        }
        //pick
        temp.push_back(i);
        solve(n, temp, ans, i+1, k);
        //backtrack
        temp.pop_back();

        solve(n, temp, ans, i+1, k);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        vector<vector<int>> ans;
        int i = 1;
        solve(n, temp, ans, i, k);

        return ans;
    }
};