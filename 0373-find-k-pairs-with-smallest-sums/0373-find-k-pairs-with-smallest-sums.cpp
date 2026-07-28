class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>> pq;

            vector<vector<int>> ans;
        for(int i = 0; i < min((int)nums1.size(), k); i++){
            pq.push({nums1[i] + nums2[0], i , 0}); //Visualise a matrix of added numbers .. push all the first numbers of each row or till k
        }
        while(k > 0 && !pq.empty()){
            auto [sum, i , j] = pq.top(); //i is the index of nums1, j is of nums2
            pq.pop();

            ans.push_back({nums1[i], nums2[j]}); //push back the nums to the ans
            //push the next element from the same row of the matrx from which the top is popped
            if(j+1 < nums2.size()){
                pq.push({nums1[i]+nums2[j+1], i , j+1});
            }
            k--;
        }
        return ans;
    }
};