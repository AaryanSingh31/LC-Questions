class Solution {
public:
    int fillCups(vector<int>& amount) {
        // priority_queue<int> pq;
        // for(int i = 0; i < 3; i++){
        //     if(amount[i] != 0) pq.push(amount[i]); //only store non zero values in the pq
        // }
        // int time = 0;
        // while(!pq.empty()){
        //     int fcup = pq.top();
        //     pq.pop(); //after popping fcup if the q become empty then it means only fcup is in the queue
        //     if(pq.empty()){
        //         time += fcup; //add the time cuz we can fill 1 cup per sec
        //         break; //break from the loop
        //     }
        //     //if queue is not empty.
        //     int scup = pq.top(); //second cup
        //     pq.pop();
        //     if(fcup > 1) pq.push(fcup-1); //if fcup freq is more than 1 then only push it back in the queue with one decrement as we've filled it.
        //     if(scup > 1)pq.push(scup-1);
        //     time++; //1 sec passed if we filled fcup and scup
        // }
        // return time;
        //CONSTANT TIME SOLUTION.
        //SINCE THERE ARE ONLY THREE ELEMENTS WE CAN FIND OUT THE MIN TIME
        //MIN WILL BE THE CEIL OF THE TOTAL ELEMENTS DIVIDE BY 2 (DIVIDE BY 2 BECAUSE WE CAN FILL MAX 2 CUPS AT A TIME)AND OTHER MINIMUM CONSTRAINT IS MAXIMUM ELEMENT'S VALUE.. SO WE'LL RETURN THE MAX OF BOTH MINIMUM'S VAL.
        int total = amount[0] + amount[1] + amount[2];
        int minTime = ceil(total/2.0); //divide by 2 because we can fill 2 cups max at a time //ceil up ke liye floating division karo
        int maxEl = max({amount[0], amount[1], amount[2]});
        return max(maxEl, minTime);
    }
};