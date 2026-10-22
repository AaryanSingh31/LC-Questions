
class Solution {
public:
    bool isAsc(vector<int>& nums, int& minIdx) {
        int n = nums.size();

        // 0 se start karke circular order check karo
        for (int i = 0; i < n; i++) {
            int currIdx = (minIdx + i) % n;
            int nextIdx = (minIdx + i + 1) % n;

            int curr = nums[currIdx];
            int next = nums[nextIdx];

            // Next element current se 1 bada hona chahiye
            if (next != (curr + 1)%n) {
                return false;
            }
        }

        return true;
    }

    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int minIdx = 0;

        // 0 ka index find karo
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                minIdx = i;
                break;
            }
        }

        // Original array ka ascending order check karo
        bool asc = isAsc(nums, minIdx);

        if (asc) {
            return min(minIdx, n - minIdx + 2);
        }

        // Array ko reverse karke dobara check karo
        reverse(nums.begin(), nums.end());

        minIdx = n - minIdx - 1;

        bool dsc = isAsc(nums, minIdx);

        if (!dsc) {
            return -1;
        }

        return min(minIdx + 1, n - minIdx + 1);
    }
};
