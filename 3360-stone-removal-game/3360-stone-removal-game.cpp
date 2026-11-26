class Solution {
public:
    bool canAliceWin(int n) {
        int i =10;
        bool flag = true;
        while(n >= 0){
            n = n-i;
            i--;
            // i--;
            flag = !flag;
        }
        return flag;  
    }
};