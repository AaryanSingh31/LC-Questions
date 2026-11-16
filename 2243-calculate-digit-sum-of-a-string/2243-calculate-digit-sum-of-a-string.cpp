class Solution {
public:
    string reSize(string s, int k){
        string temp;
        for(int i = 0; i < s.size(); i+=k){
            int sum = 0;
            for(int j = i; j < min(i+k, (int)s.size()); j++){
                int num = s[j] - '0'; 
                sum += num;
            }
            cout<<sum<<" ";
            temp += to_string(sum);
        }
        return temp;
    }
    string digitSum(string s, int k) {
        if(s.size() <= k){
            return s;
        }
        string temp = reSize(s, k);
        while(temp.size() > k){
            temp = reSize(temp, k);
        }
        return temp;
    }
};