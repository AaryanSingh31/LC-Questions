class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        long long sum = 0;
        string ans = "";
        for(int i = 0; i < shifts.size(); i++){
            sum += shifts[i];
        }
        for(int i = 0; i < shifts.size(); i++){
            char ch = s[i];
            ans += 'a' + (ch-'a'+ sum) % 26;
            sum -= shifts[i];
        }
        return ans;
    }
};