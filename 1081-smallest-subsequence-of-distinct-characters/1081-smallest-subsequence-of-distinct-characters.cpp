class Solution {
public:
    string smallestSubsequence(string s) {
        unordered_set<char> present;
        string st;
        unordered_map<char, int> freq;
        for(char c : s){
            freq[c]++;
        }
        for(char ch : s){
            freq[ch]--; ///next char of s.. visit means decrease the freq of it.
            if(present.count(ch)){
                continue;
            }
            while (!st.empty() && st.back() > ch && freq[st.back()] > 0){
                present.erase(st.back());
                st.pop_back();
            }
            st.push_back(ch);
            present.insert(ch);
        }
        return st;
    }
};