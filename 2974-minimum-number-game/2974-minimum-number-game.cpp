class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int num : nums){
            pq.push(num);
        }
        vector<int> ans;
        while(!pq.empty()){
            int first = pq.top();
            pq.pop();
            int sec = 0;
            if(pq.top()){
                sec = pq.top();
                pq.pop();
                ans.push_back(sec);
            }
            ans.push_back(first);
        }
        return ans;
    }
};