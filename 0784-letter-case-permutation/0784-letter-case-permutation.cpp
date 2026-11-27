class Solution {
public:
void solve(string &s, vector<string> &ans, int i, string &temp, int n){
    if(i == n){
        ans.push_back(temp);
        return;
    }
    if(s[i] >= '0' && s[i] <= '9'){
        temp += s[i];
        solve(s, ans, i+1, temp, n);
        temp.pop_back();
        return;
    }else {
        temp += tolower(s[i]);
        solve(s, ans, i+1, temp, n);
        temp.pop_back();
        
        temp += toupper(s[i]);
        solve(s, ans, i+1, temp, n);
        temp.pop_back();
    }
}
    vector<string> letterCasePermutation(string s) {
        int n = s.length();
        string temp = "";
        vector<string> ans;

        solve(s, ans, 0, temp, n);

        return ans;
    }
};