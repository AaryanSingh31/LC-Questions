class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for(int st = 1; st <= 9; st++){
            int num = 0;
            for(int i = st; i <= 9; i++){
                num = num * 10 + i;

                if(num >= low && num <= high){
                    ans.push_back(num);
                }
                if(num > high){
                    break;
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};