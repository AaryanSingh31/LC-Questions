class Solution {
public:
    int maxSubarrayLength(vector<int>& s, int k) {
        int n = s.size();
        unordered_map<int, int> mp;
        int l = 0;
        int maxLen = INT_MIN;
        for(int r = 0; r < n; r++){
            if(mp.find(s[r]) != mp.end()){
                while(mp[s[r]] >= k){
                    mp[s[l]]--;
                    l++;
                    if(mp[s[l]] == 0){
                        mp.erase(s[l]);
                    }
                }
            }
            mp[s[r]]++;
            maxLen = max(r-l+1, maxLen);
        }
        return maxLen;
    }
};