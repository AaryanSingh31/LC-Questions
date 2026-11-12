class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int maxCnt = 1, cnt = 1;
        for(int r = 0; r < n-1; r++){
            if(nums[r] < nums[r+1]){
                cnt++;
            }else {
                cnt = 1;
            }
            maxCnt = max(maxCnt, cnt);
        }
        cnt = 1;
        for(int r = 0; r < n-1; r++){
            if(nums[r] > nums[r+1]){
                cnt++;
            }else {
                cnt = 1;
            }
            maxCnt = max(maxCnt, cnt);
        }
        return maxCnt;
    }
};