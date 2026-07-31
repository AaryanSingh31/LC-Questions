class Solution {
public:
    int minimumPushes(string word) {
        map<char, int> mp;
        int ans = 0;
        for(char ch : word){
            mp[ch]++;
        }
        vector<int> v;
        for(auto &it : mp){
            v.push_back(it.second);
        }
        sort(v.begin(), v.end(), greater<int>());
        for(int i = 0; i < v.size(); i++){
            int cl = (i/8) + 1;
            ans += cl * v[i];
        }
        return ans;
    }
};