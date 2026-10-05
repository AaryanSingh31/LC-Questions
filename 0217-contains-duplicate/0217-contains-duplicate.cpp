class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;

        for(int i = 0; i < nums.size(); i++){
            int x = nums[i];

            if(s.find(x) != s.end()){
                return true;
            }
            s.insert(x);
        }
        return false;
    }
};