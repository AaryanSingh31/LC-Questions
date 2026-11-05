class Solution {
public:
    vector<vector<int>> ans;
    void solve(int i, vector<int> &temp, int need, int k){
        if(temp.size() == k && need == 0){
            ans.push_back(temp);
            return;
        }
        if(i > 9 || need < 0){
            return;
        }
        //pick
        temp.push_back(i);
        solve(i+1, temp, need-i, k);
        //backtrack
        temp.pop_back();
        //pick not

        solve(i+1, temp, need, k);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        int need = n;
        int i = 1;
        solve(i, temp, need, k);

        return ans;
    }
};