class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            int n ='z'- ch + 1;
            sum += n*(i+1);
        }
        return sum;
    }
};