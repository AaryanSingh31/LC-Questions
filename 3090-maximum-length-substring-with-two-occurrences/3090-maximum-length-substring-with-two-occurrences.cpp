class Solution {
public:
    int maximumLengthSubstring(string s) {
        int maxLen = INT_MIN;
        int l = 0;
        unordered_map<int, int> mp;
        for(int i = 0; i < s.size(); i++){
            mp[s[i]]++;
            while(mp[s[i]] > 2){
                mp[s[l]]--;
                    l++;
            }
            maxLen = max(maxLen, i-l+1);
        }
        return maxLen;
    }
};