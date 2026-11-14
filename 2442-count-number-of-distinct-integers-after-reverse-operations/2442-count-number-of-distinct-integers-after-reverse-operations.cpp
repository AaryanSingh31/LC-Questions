class Solution {
public:
    int revDig(int n){
        int num = 0;
        while(n){
            int ld = n%10;
            num = 10*num + ld;
            n/=10;
        }
        return num;
    }
    int countDistinctIntegers(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            st.insert(nums[i]);
        }
        cnt = st.size();
        for(int i = 0; i < n; i++){
            if(st.find(revDig(nums[i])) == st.end()){
                cnt++;
                st.insert(revDig(nums[i]));
            }
        }    
        return cnt;
    }
};