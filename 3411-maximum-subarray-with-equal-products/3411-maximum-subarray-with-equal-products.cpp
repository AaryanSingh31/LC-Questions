class Solution {
public:
    int maxLength(vector<int>& nums) {
        //generating all the subarrays
        int n = nums.size();
        int maxLen = 0;
        
        for(int i = 0; i < n; i++){
            long long prod = 1, g = 0, l = 1;
            for(int j = i; j < n; j++){
                
                if(prod > LLONG_MAX/nums[j]){
                    break;
                }
                prod *= nums[j];
                l = lcm(l, nums[j]);
                g = gcd(g, nums[j]);
               
                if(prod == l * g){
                    maxLen = max(maxLen, j-i+1);
                }
            }
        }
        return maxLen;
    }
};