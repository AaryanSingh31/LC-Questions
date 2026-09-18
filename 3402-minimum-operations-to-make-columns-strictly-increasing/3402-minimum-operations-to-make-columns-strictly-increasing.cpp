class Solution {
public:
    int minimumOperations(vector<vector<int>>& nums) {
        int m = nums.size(), n = nums[0].size();

        int cnt = 0;
        for(int j = 0; j < n; j++){
            for(int i = 0; i < m-1; i++){
                if(nums[i+1][j] <= nums[i][j]){
                    cnt += (nums[i][j]-nums[i+1][j]+1);
                    nums[i+1][j] = nums[i+1][j] + (nums[i][j]-nums[i+1][j]+1);
                }
            }
        }
        return cnt;
    }
};