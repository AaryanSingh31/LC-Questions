class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int, char>> pq;
        unordered_map<char, int> mp; 
        for(char ch : s){
            mp[ch]++;
        }
        for(auto& it : mp){
            pq.push({it.second, it.first});
        }
        string ans;
        while(!pq.empty()){
            int freq = pq.top().first;
            char ch = pq.top().second;
            pq.pop();
            while(freq > 0){
                ans += ch;
                freq--;
            }
        }
        return ans;
    }
};