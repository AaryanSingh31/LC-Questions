class Solution {
public:
    string solve(string str){
        int sum = 0;
        for(int i = 0; i < str.size(); i++){
            char ch = str[i];
            int num = ch-'0';
            sum += num;
        }
        return to_string(sum);
    }
    string conv(string s){
        string ans;
        for(int i = 0; i < s.size(); i++){
            int num = s[i]-'a' + 1;
            ans += to_string(num);
        }
        return ans;
    }
    int getLucky(string s, int k) {
        string str = conv(s);
        cout<<str<<" ";
        int cnt = 0;
        
        while(cnt < k){
            str = solve(str);
            cnt++;
        }
        return stoi(str);
    }
};