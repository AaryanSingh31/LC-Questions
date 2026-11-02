class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cnt = 0;
        int n = nums.size();
        int mid = n/2;

        for(int i = 0; i < n; i++){
            cnt += abs(nums[i]-nums[mid]);
        }
        return cnt;
    }
};