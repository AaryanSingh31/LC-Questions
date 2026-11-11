class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long minSum = 0;
        long long mini = min(need1, need2);
        long long maxi = max(need1, need2);
        minSum += mini * min((long long)costBoth, (long long)cost1 + cost2);
        if(need1-mini == 0){
            minSum += abs(maxi-mini) * min(costBoth, cost2);
        }else {
            minSum += abs(maxi-mini) * min(costBoth, cost1);
        }
        return minSum;
    }
};