class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;
        string ans;
        for(char ch : s) mp[ch]++;
        priority_queue<pair<int, char>> pq;
        for(auto & it : mp){
            pq.push({it.second, it.first});
        }
        pair<int , char> prev = {0, '#'}; //pair to store the prev pair of the queue to make the alteranate pop.
        while(!pq.empty()){
            auto curr = pq.top(); //curr is the current pair
            pq.pop();
            ans += curr.second; //add the char to the ans
            curr.first--; //decrease its freq as it is used

            //push the prev pair if it has freq remaining
            if(prev.first > 0){
                pq.push(prev);
            }
            prev = curr; //make the curr new prev for next iteration
        }
        if(ans.size() != s.size()) return ""; //
        return ans;
    }
};