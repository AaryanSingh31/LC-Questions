class Solution {
public:
    bool sumGame(string nums) {
        int n = nums.size();
        int s1 = 0, s2 = 0;
        int c1 = 0, c2 = 0;

        for(int i = 0; i < nums.size(); i++){
            if(i < n/2){
                if(nums[i] == '?') c1++;
                else s1 += nums[i] - '0';
            }else {
                if(nums[i] == '?') c2++;
                else s2 += nums[i] - '0';
            }
        }
        if((c1+c2) % 2 == 1){
            return true;
        }else if(s1-s2 == (9*(c2-c1))/2){
            return false;
        }
        return true;
    }
};