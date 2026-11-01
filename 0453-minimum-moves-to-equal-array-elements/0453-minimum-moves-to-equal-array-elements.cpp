class Solution {
public:
    int minMoves(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        int mini = *min_element(nums.begin(), nums.end());
        for(int i = n-1; i >= 0; i--){
            cnt += nums[i]-mini;
        }
        return cnt;
    }
};