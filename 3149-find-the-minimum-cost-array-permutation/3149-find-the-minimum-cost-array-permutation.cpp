class Solution {
public:
    void solve(vector<int> &nums, int n, int &minScore, vector<bool> &visited, vector<int> &perm, vector<int> &resPerm, int score){
        if(score > minScore) return;
        if(perm.size() == n){
            score += abs(perm.back() - nums[perm[0]]);
            if(minScore > score){
                minScore = score;
                resPerm = perm;
            }
            return;
        }

        for(int num = 0; num < n; num++){
            if(!visited[num]){
                //do
                perm.push_back(num);
                visited[num] = true;

                int m = perm.size();
                //explore
                solve(nums,n,minScore,visited, perm, resPerm, score + abs(perm[m-2] - nums[perm[m-1]]));
                //backtrack
                perm.pop_back();
                visited[num] = false;
            }
        }
    }
    vector<int> findPermutation(vector<int>& nums) {
        int n = nums.size();
        int minScore = INT_MAX;
        vector<bool> visited(n, false);
        vector<int> perm = {0};
        visited[0] = true;
        vector<int> resPerm;
        
        solve(nums, n, minScore, visited, perm, resPerm, 0);

        return resPerm;
    }
};