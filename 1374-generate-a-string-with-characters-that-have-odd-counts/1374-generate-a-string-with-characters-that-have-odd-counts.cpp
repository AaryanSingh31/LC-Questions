class Solution {
public:
    string generateTheString(int n) {
        string ans;
        if(n % 2 == 1){
            for(int i = 1; i <= n; i++){
                ans += 'a';
            }
        }else {
            ans = 'b';
            for(int i = 1; i < n; i++){
                ans += 'a';
            }
        }
        return ans;
    }
};