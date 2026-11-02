class Solution {
public:
    int partition(vector<int> &nums, int low, int high){
        int pvt = nums[high];
        int i = low;
        for(int j = low; j < high; j++){
            if(nums[j] <= pvt){
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[i], nums[high]);
        return i;
    }
    int quickSelect(vector<int>& nums, int low, int high, int k){

        if(low <= high){
            int curIdx = partition(nums, low, high);

            if(curIdx == k){
                return nums[curIdx];
            }else if(curIdx < k){
                return quickSelect(nums, curIdx+1, high, k);
            }else {
                return quickSelect(nums, low, curIdx-1, k);
            }
        }
        return -1;
    }
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1;
        int k = n/2;
        int median = quickSelect(nums, low, high, k);
        int cnt = 0;
        for(int i = 0; i < n; i++){
            cnt += abs(nums[i]-median);
        }
        return cnt;
    }
};