class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>,vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i = 0; i < nums.size(); i++){
            pq.push({nums[i], i});
        }
        while(k > 0){
            int num = pq.top().first;
            int index = pq.top().second;
            pq.pop();
            nums[index] = num * multiplier;
            pq.push({num*multiplier, index});
            k--;
        }
        return nums;
    }
};