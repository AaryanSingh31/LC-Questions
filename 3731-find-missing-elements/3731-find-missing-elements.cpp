class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int st = 0, end = nums.size()-1;
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i+1]-nums[i] > 1){
                int diff = nums[i+1] - nums[i];
                int add = 1;
                while(diff != 1){
                ans.push_back(nums[i]+add);
                add++;
                diff--;
                }
            }
        }
        return ans;
    }
};