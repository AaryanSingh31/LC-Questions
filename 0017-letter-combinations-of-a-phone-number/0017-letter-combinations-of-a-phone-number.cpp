class Solution {
public:
    vector<string> ans;
    map<char, string> mp{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
    void solve(int idx, string temp, string s){
        if(idx >= s.length()){
            ans.push_back(temp);
            return;
        }
        char ch = s[idx];
        string str = mp[ch];
        for(int i = 0; i < str.length(); i++){
            temp.push_back(str[i]); //do
            solve(idx+1, temp, s);

            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        int idx = 0;
        string temp = "";
        solve(idx, temp, digits);

        return ans;
    }
};