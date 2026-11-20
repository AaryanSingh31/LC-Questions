class Solution {
public:
    void solve(int i, string &temp, unordered_set<string> &st, int cnt, int &maxLen, int n, string& s){
        if(cnt < 0) return;
        if(i == n){
            if(cnt == 0){
                if(temp.length() > maxLen){
                    maxLen = temp.length();
                    st.clear();
                }
                if(temp.length() == maxLen){
                    st.insert(temp);
                }
            }
            return;
        }

        if(s[i] != '(' && s[i] != ')'){
            temp.push_back(s[i]);
            solve(i+1, temp,st, cnt, maxLen,n,s);
            temp.pop_back();
            return;
        }
        //pick
        temp.push_back(s[i]); //do
        solve(i+1, temp, st, cnt + (s[i] == '(' ? 1 : -1), maxLen, n, s); //explore
        temp.pop_back(); //backtrack

        //pick not
        solve(i+1, temp, st, cnt, maxLen, n, s);


    }
    vector<string> removeInvalidParentheses(string s) {
        int n = s.length();
        unordered_set<string> st;
        int maxLen = 0;
        string temp = "";
        solve(0, temp, st, 0, maxLen, n, s);

        return vector<string>(st.begin(), st.end());
    }
};