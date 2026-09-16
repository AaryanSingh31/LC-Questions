class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        int l = 0, r = n/2;
        long long prefix = 0, suffix = 0;
        for(int i = 0; i < n; i++){
            if(i < n/2){
                prefix += nums[i];
            }else suffix += nums[i];
        }
        for(int k = 0; k  < n; k++){
            if(prefix > suffix) cnt++;
            prefix -= nums[l];
            prefix += nums[r];
            suffix -= nums[r];
            suffix += nums[l];
            l++;
            r = (r+1)%n;
        }    
        return cnt;
    }
};


