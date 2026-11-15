class Solution {
public:
    int numOfSubarrays(vector<int>& nums) {
        int n = nums.size();
       long long sum = 0;
        long long ans = 0, evenC = 1, oddC = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            if(sum % 2 == 0){
                ans += oddC;
                evenC++;
            }else {
                ans += evenC;
                oddC++;
            }
            
        }
        return ans % 1000000007;
    }
};