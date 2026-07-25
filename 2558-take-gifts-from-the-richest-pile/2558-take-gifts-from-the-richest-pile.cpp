class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        for(int i = 0; i < gifts.size(); i++){
            pq.push(gifts[i]);
        }
        while(k > 0 && !pq.empty()){
            int larg = pq.top();
            pq.pop();
            pq.push(floor(sqrt(larg)));
            k--;
        }
        long long ans = 0;
        while(pq.size() > 0){
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};