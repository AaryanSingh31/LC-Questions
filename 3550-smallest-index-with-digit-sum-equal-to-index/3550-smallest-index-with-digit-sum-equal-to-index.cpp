class Solution {
public:
    int sumOfDig(int n){
        int ans = 0;
        while(n>0){
            ans += n%10;
            n/= 10;
        }
        return ans;
    }
    int smallestIndex(vector<int>& nums) {
        int ans = 1001;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(sumOfDig(nums[i]) == i)
            ans = min(ans, i);
        }
        return ans == 1001 ? -1 : ans;
    }
};