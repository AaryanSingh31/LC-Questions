class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> p;
        for(int i = 0; i < nums.size(); i++){
            p.push(nums[i]);
        }
        int ans = 0;
        while(k > 0 && !p.empty()){
            ans = p.top();
            p.pop();
            k--;
        }
        return ans;
    }
};