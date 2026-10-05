class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int cntP = 0, cntN = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0) continue;

            if(nums[i] < 0){
                cntN++;
            }else {
                cntP++;
            }
        }
        if(cntN > cntP){
            return cntN;
        }
        return cntP; 
    }
};