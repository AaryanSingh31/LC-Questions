class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int minSum = INT_MAX;
        while(l <= r){
            int sum = 0;
            //window Creation
            for(int i = 0; i < l; i++){
                sum += nums[i];
            }
            if(sum > 0) minSum = min(sum, minSum);
            for(int i = l; i < nums.size(); i++){
                sum += nums[i];
                sum -= nums[i-l];

                if(sum > 0) minSum = min(minSum, sum);
            }
            l++;
        }
        return minSum == INT_MAX ? -1 : minSum;

    }
};