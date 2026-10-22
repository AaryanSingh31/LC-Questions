class Solution {
public:
    bool isAsc(vector<int> &nums, int &minIdx){
        int n = nums.size();
        int i;
        for(i = minIdx; i < n+minIdx; i++){
            if(nums[(i+1)%n]-1 != nums[i%n]){
                break;
            }
        }
        if((i+1)%n == minIdx) return true;
        return false;
    }
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int minIdx = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                minIdx = i;
                break;
            }
        }
        bool asc = isAsc(nums, minIdx);
        bool dsc = false;

        if(!asc){
            reverse(nums.begin(), nums.end());
            minIdx = n-minIdx-1;
            dsc = isAsc(nums, minIdx);
        }

        if(!asc && !dsc){
            return -1;
        }
        if(asc){
            return min(minIdx, 2+n-minIdx);
        }
        return min(1+minIdx, (n-minIdx+1));
    }
};