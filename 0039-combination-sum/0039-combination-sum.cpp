class Solution {
public:
    void solve(int i, vector<int> &nums, vector<vector<int>> &ans, vector<int> &temp, int need){
        if(need == 0){
            ans.push_back(temp);
            return;
        }

        if(i == nums.size() || need < 0){ //base case of the index reaches the end or the need is < 0
            return;
        }
        //pick
        temp.push_back(nums[i]);
        solve(i, nums, ans, temp, need-nums[i]);
        //backtrack
        if(temp.size() != 0) temp.pop_back();

        //pick not
        solve(i+1, nums, ans, temp, need);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int i = 0; //index of the nums
        vector<vector<int>> ans;
        vector<int> temp;
        int need = target;

        solve(i, nums, ans, temp, need);

        return ans;
    }
};