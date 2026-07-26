class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<
        pair<int, int>, 
        vector<pair<int, int>>, 
        greater<pair<int, int>>
        > pq;
        for(int i = 0; i < nums.size(); i++){
            pq.push({nums[i], i});

            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<int> ans;
        vector<pair<int, int>> v;
        //Store all the queue values into a vector pair
        while(!pq.empty()){
           v.push_back(pq.top());
           pq.pop();
        }
        //sort the vector pair index wise. ie, custom sort according to the second val in pair(which is index)
        sort(v.begin(), v.end(), [](auto &a, auto &b){
            return a.second < b.second;
        });

        //Now the vector is sorted according to the index
        for(int i = 0; i < v.size(); i++){
            ans.push_back(v[i].first); //push back the values in indices to the ans
        }
        return ans;
    }
};