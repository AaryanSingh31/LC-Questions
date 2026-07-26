class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        // return (nums[nums.size()-1]-1) * (nums[nums.size()-2]-1);
        //USING PRIORITY QUEUE
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < nums.size(); i++){
            pq.push(nums[i]);

            if(pq.size() > 2){
                pq.pop();
            }
        }
        int ans = 1;
        while(!pq.empty()){
            ans *= pq.top()-1;
            pq.pop();
        }
        return ans;
    }
};