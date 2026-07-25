class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> pq;
        for(int i = 0; i < 3; i++){
            if(amount[i] != 0) pq.push(amount[i]);
        }
        int time = 0;
        while(!pq.empty()){
            int fcup = pq.top();
            pq.pop();
            if(pq.empty()){
                time += fcup;
                break;
            }
            int scup = pq.top();
            pq.pop();
            if(fcup > 1) pq.push(fcup-1);
            if(scup > 1)pq.push(scup-1);
            time++;
        }
        return time;
    }
};