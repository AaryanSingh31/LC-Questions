class Solution {
public:

    int n;
    unordered_set<string> st;
    vector<string> ans;

    void solve(int idx, string sent, string s){
        if(idx >= n){
            ans.push_back(sent);
            return;
        }

        for(int j = idx; j < n; j++){
            string temp = s.substr(idx, j-idx+1);
            
            if(st.count(temp)){
                string tempSent = sent;
                if(!sent.empty()){
                    sent += " ";
                }
                sent += temp; //do
                solve(j+1, sent, s); //exp
                sent = tempSent; //backtrack
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        n = s.length();
        for(int i = 0; i < wordDict.size(); i++){
            st.insert(wordDict[i]);
        }
        string sent;
        solve(0, sent, s);

        return ans;
    }
};