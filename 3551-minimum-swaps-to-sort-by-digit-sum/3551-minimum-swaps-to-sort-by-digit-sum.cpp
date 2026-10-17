class Solution {
public:
    int digSum(int n){
        long long sum = 0;
        while(n > 0){
            int ld = n%10;
            sum += ld;
            n/=10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {

        vector<int> exp = nums;
        auto lambda = [this](int num1, int num2){
            int d1 = digSum(num1);
            int d2 = digSum(num2);
            if(d1 != d2){
                return d1 < d2; //if dig sum is not equal then return num1 if d1 is smaller else num2
            }
            return num1 < num2; //if the dig Sum is same then return num1 if it is smaller else return num2;
        };

        sort(begin(exp), end(exp), lambda);

        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]] = i;
        }
        int swapC = 0;
        for(int i = 0; i < exp.size(); i++){
            if(exp[i] == nums[i]) continue;
            
            int idx = mp[exp[i]];
            swap(nums[i], nums[idx]);
            swapC++;

            mp[nums[idx]] = idx;
            mp[nums[i]] = i;
        }
        return swapC;
    }
};