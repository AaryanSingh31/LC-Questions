class Solution {
public:
    vector<vector<string>> ans;
    int n;
    bool isPalindrome(string &s, int r, int l){
        while(l < r){
            if(s[l] != s[r]){
                return false;
            }
            l++, r--;
        }
        return true;
    }
    void solve(string &s, vector<string> &temp, int idx){
        if(idx == n){
            ans.push_back(temp);
            return;
        }

        for(int i = idx; i < n; i++){
            if(isPalindrome(s, i, idx)){
                temp.push_back(s.substr(idx, i-idx+1));
                solve(s, temp, i+1);

                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        n = s.length();
        vector<string> temp;
        int idx = 0;
        solve(s, temp, idx);

        return ans;
    }
};