class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> p;
        for(int i = 0; i < stones.size(); i++){
            p.push(stones[i]);
        }
        while(p.size() > 1){
            int first = p.top(); //weight of 1st stone
            p.pop();
            int sec = p.top(); //weight osf sec stone.
            p.pop();
            int rem = first - sec; //rem weight after collision
            p.push(rem); //push the remaining weight.
        }
        //if one element remains the queue .. return it
        if(p.top()){
            return p.top();
        }//else - if queue goes empty return 0
        return 0;
    }
};