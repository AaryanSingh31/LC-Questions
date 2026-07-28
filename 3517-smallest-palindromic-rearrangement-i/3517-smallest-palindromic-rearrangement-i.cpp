class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);
        for(int i = 0; i < s.size(); i++){
            freq[s[i]-'a']++;
        }
        string l = "";
        string mid ="";
        for(int i = 0; i < freq.size(); i++){
            l += string(freq[i]/2, char(i+'a'));
            if(freq[i]% 2 == 1){
                mid = char(i + 'a');
            }
        }
        string r = l;
        reverse(r.begin(), r.end());
        return l + mid + r;
    }
};