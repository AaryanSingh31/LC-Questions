class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        vector<int> prefix(n+1, 0), suffix(n+1, 0);
        unordered_map<int, int> mp;
        if(n == 1 && nums[0] == x){
            return 1;
        }
        int fByPrefix = INT_MAX, fBySuffix = INT_MAX, fByBoth = INT_MAX;
        for(int i = 0; i < n; i++){
            prefix[i+1] = prefix[i] + nums[i];
        }
        for(int i = n-1; i >= 0; i--){
            suffix[n-i] = suffix[n-i-1] + nums[i]; 
        }
        for(int i = 1; i <= n; i++){
            mp[suffix[i]] = i;
        }        
        for(int i = 0; i < n; i++){
            if(prefix[i] == x){
                fByPrefix = i;
            }
            if(suffix[i] == x){
                fBySuffix = i;
            }
        }
        for(int i = 1; i <= n; i++){
            int need = x-prefix[i];
            if(mp.count(need) && i + mp[need] <= n){
            fByBoth = min(fByBoth, mp[need] + i);
}
        }
        cout<<fByPrefix<<endl;
        cout<<fBySuffix<<endl;
        cout<<fByBoth<<endl;

        int ans = min({fByPrefix, fBySuffix, fByBoth});
        if(ans == INT_MAX){
            return -1;
        }
        return ans;    
    }
};