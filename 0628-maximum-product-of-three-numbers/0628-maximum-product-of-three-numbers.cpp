class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int minus = nums[0] * nums[1] * nums[n-1]; //ans can be two minus val from the start if they exist and they will be the largest minus val as array is sorted.. and one last val from the end of the array cuz it will always be the largest
        int plus = nums[n-1] * nums[n-2] * nums[n-3]; //or ans can be all three positive max values from the end.
        return max(minus, plus); //return wichever is larger.
    }
};