class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> p;
        for(int i = 0; i < stones.size(); i++){
            p.push(stones[i]);
        }
        while(p.size() > 1){
            int first = p.top();
            p.pop();
            int sec = p.top();
            p.pop();
            int rem = first - sec;
            p.push(rem);
        }
        if(p.top()){
            return p.top();
        }
        return 0;
    }
};