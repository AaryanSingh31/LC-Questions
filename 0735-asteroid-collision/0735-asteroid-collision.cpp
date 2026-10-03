class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        for(int curr = 0; curr < n; curr++){
            while(!st.empty() && nums[curr] < 0 && st.top() > 0 && abs(st.top()) < abs(nums[curr])){
                st.pop();
            }
            if(!st.empty() && nums[curr] < 0 && st.top() > 0 && abs(st.top()) == abs(nums[curr])){
                st.pop();
            }else if(st.size() == 0 || st.top() < 0 || nums[curr] > 0){
                st.push(nums[curr]);
            }
        }

        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};