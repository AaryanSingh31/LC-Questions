class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int time = 0;
        vector<int> mp(26, 0);
        for(char & ch : tasks){
            mp[ch-'A']++;
        }
        priority_queue<int> pq;
        //push in pq
        for(int i = 0; i < 26; i++){
            if(mp[i] > 0){
                pq.push(mp[i]);
            }
        }
        while(!pq.empty()){
            vector<int> temp;

            //tasks in 1 interval
            for(int i = 1; i <= n+1; i++){
                if(!pq.empty()){
                int freq = pq.top();
                pq.pop();
                freq--;
                temp.push_back(freq);
                }
            }
            for(int & num: temp){
                if(num > 0){
                    pq.push(num);
                }
            }
            if(pq.empty()){
                time += temp.size();
            }else {
                time += n+1;
            }
        }
        return time;
    }
};