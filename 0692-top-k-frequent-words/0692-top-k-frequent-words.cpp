class Solution {
public:
    struct cmp {
        bool operator()(pair<int, string>& a, pair<int, string>& b) {
            // Frequency same
            if (a.first == b.first) //if freq is same
                return a.second < b.second; //if true toh b ki priority jyada (mtlb b upar) agar true h ye toh a ki priority jyada mtlb queue mein a upar
            // Frequency different
            return a.first > b.first;  // if freq is diff
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;
        unordered_map<string, int> mp;
        for(string str : words){
            mp[str]++;
        }
        for(auto &it : mp){
            pq.push({it.second, it.first});

            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<string> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};