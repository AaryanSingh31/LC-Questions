class Solution {
public:
    vector<vector<int>> ans;
    unordered_map<int, int> mp;
    
    void solve(vector<int> &temp, vector<int> &nums){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }
        unordered_set<int> used;

        for(int i = 0; i < nums.size(); i++){
            if(mp.find(nums[i]) != mp.end() && used.find(nums[i]) == used.end()){
                mp[nums[i]]--;
                used.insert(nums[i]);
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
                temp.push_back(nums[i]);
                solve(temp, nums);

                temp.pop_back();
                mp[nums[i]]++;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }
        vector<int> temp;
        solve(temp, nums);
        return ans;
    }
};