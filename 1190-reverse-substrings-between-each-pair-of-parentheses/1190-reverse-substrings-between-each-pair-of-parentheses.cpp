class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        int n = s.size();
        for(int i = 0; i < n; i++){
            string str;
            if(s[i] == ')'){
                while(!st.empty() && st.top() != '('){
                    str += st.top();
                    st.pop();
                }
                st.pop();
                for(char &ch : str){
                    st.push(ch);
                }
            }
            if(s[i] != ')') st.push(s[i]);
        }
        string ans;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};