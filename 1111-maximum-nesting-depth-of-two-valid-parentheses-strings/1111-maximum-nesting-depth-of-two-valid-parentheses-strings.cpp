class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int curD = 0;
        vector<int> ans;

        for(char ch : seq) {
            if(ch == '(') {
                curD++;
                ans.push_back(curD % 2 == 1 ? 0 : 1);
            }
            else {
                ans.push_back(curD % 2 == 1 ? 0 : 1);
                curD--;
            }
        }

        return ans;
    }
};