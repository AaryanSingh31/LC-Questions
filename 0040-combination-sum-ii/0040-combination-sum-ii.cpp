class Solution {
public:
    void solve(int i, vector<vector<int>> &ans, vector<int> &temp, vector<int> &nums, int need){
        if(need == 0){
            ans.push_back(temp);
            return;
        }
        if(i == nums.size() || need < 0){
            return;
        }

        //pick
        temp.push_back(nums[i]);
        solve(i+1, ans, temp, nums, need-nums[i]); //explore
        temp.pop_back(); //backtrack

        //pick not
        int j = i+1;
        while (j < nums.size() && nums[j] == nums[i]) {
            j++;
        }
        solve(j, ans, temp, nums, need);
        
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        vector<vector<int>> ans;
        int i = 0, need = target;
        solve(i, ans, temp, nums, need);

        return ans;
    }
};