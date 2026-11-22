class Solution {
public:
    bool checkString(string s) {
        int ac = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'a') ac++;
        }
        if(ac == 0) return true;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'a') ac--;
            if(s[i] == 'b' && ac != 0){
                return false;
            }
        }
        return true;
    }
};