class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> freq;
        for (int x : nums) freq[x]++;

        for (auto p : freq)
            if (p.second == 1) return p.first;
        return -1;
    }
};