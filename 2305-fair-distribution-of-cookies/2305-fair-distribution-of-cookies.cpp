class Solution {
public:
    int res = INT_MAX;
    int n;
    void solve(int idx, vector<int> &dist, vector<int>& cookies, int k){
        if(idx >= n){
            int maxi = *max_element(dist.begin(), dist.end());

            res = min(res, maxi);
            return;
        }

        int cookie = cookies[idx];
        for(int i = 0; i < k; i++){
            dist[i] += cookie;
            solve(idx+1, dist ,cookies, k);

            dist[i] -= cookie;
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> dist(k, 0);
        n = cookies.size();
        int idx = 0;
        solve(idx ,dist, cookies, k);

        return res;
    }
};