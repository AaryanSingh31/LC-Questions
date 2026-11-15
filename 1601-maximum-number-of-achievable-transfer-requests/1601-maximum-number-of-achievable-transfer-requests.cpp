class Solution {
public:
    int m;
    int maxi = 0;
    bool allZ(vector<int> &nums){
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                return false;
            }
        }
        return true;
    }
    void solve(int idx, vector<vector<int>>& requests, int cnt, vector<int> &res){

        if(idx >= m){
            if(allZ(res)){
                maxi = max(maxi, cnt);
            }
            
            return;
        }
        //pick
        int from = requests[idx][0];
        int to   = requests[idx][1];
        res[from] -=1;
        res[to] += 1;
        //explore
        solve(idx+1, requests, cnt+1, res);
        //bt
        res[from] += 1;
        res[to] -= 1;
        //pick not
        solve(idx+1, requests, cnt, res);

    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        m = requests.size();
        int cnt = 0;
        vector<int> res(n, 0);
        solve(0, requests, cnt, res);

        return maxi;
    }
};