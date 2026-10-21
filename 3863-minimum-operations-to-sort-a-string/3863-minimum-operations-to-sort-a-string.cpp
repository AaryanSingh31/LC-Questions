class Solution {
public:
    bool isIn(string s, int mini, int maxi){
        for(int i = 0; i < s.size(); i++){
            if(s[i] == mini || s[i] == maxi){
                return true;
            }
        }
        return false;
    }
    bool isS(string s){
        for(int i = 0; i < s.size()-1; i++){
            if(s[i] > s[i+1]){
                return false;
            }
        }
        return true;
    }    
    int minOperations(string s) {
        int n = s.size();
        char mini = 'z', maxi = 'a';
        string str = s.substr(1, n-2);
        for(int i = 0; i < s.size(); i++){
            mini = min(mini, s[i]);
            maxi = max(maxi, s[i]);
        }
        if(isS(s)){
            return 0;
        }else if(s.size() == 2){
            return -1;
        }
        else if(maxi == s[n-1] || mini == s[0]){
            return 1;
        }else if(isIn(str, mini, maxi)){
            return 2;
        }else return 3;
    }
};