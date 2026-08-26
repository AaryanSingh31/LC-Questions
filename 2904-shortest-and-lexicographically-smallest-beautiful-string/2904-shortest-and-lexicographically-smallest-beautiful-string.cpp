class Solution{
public:
    string shortestBeautifulSubstring(string s, int k){
        string ans = "";
        int cnt = 0, l = 0;

        for(int r = 0; r < s.length(); r++){
            if(s[r] == '1') {
                cnt++;
            }

            while(cnt > k){
                if(s[l] == '1'){
                    cnt--;
                }
                l++;
            }
            while(cnt == k && s[l] == '0') {
                l++;
            }
            if(cnt == k){
                string curr = s.substr(l, r - l + 1);

                if(ans == "" ||
                   curr.size() < ans.size() ||
                   (curr.size() == ans.size() && curr < ans)){
                    ans = curr;
                }
            }
        }
        return ans;
    }
};