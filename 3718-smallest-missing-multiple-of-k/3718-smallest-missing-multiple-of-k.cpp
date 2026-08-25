class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int mult = 1;
        unordered_set<int> st;
        for(int &x : nums){
            st.insert(x);
        }
        while(true){
            if(st.find(mult*k) == st.end()){
                return mult * k;
                break;
            }else {
                mult++;
            }
        }
        return -1;
    }
};