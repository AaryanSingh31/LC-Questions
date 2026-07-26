class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int, char>> pq; //max heap according to freq
        unordered_map<char, int> mp; 
        for(char ch : s){
            mp[ch]++;
        }
        for(auto& it : mp){
            pq.push({it.second, it.first}); //build max heap according to freq
        }
        string ans;
        while(!pq.empty()){
            int freq = pq.top().first; //freq of the top element
            char ch = pq.top().second; //top element
            pq.pop();
            while(freq > 0){ //add top element freq times
                ans += ch;
                freq--;
            }
        }
        return ans;
    }
};