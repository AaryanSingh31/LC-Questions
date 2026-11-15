class Solution {
public: 
    set<vector<int>> ans;
    int n;
    bool isInc(vector<int> &nums){
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] > nums[i+1])return false;
        }
        return true;
    }
    void solve(int idx, vector<int> &temp, vector<int> &nums){
        if(temp.size() >= 2 && isInc(temp)){
            ans.insert(temp);
        }
        if(idx >= n){
            return;
        }

        //do
        temp.push_back(nums[idx]);
        //exp
        solve(idx+1, temp, nums);
        //bt
        temp.pop_back();
        //pick not
        solve(idx+1, temp, nums);

    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        n = nums.size();
        vector<int> temp;

        solve(0, temp, nums);

        return vector<vector<int>>(ans.begin(), ans.end());
    }
};