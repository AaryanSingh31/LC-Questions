class Solution {
public:
    int maxProduct(int n) {
       int larg = INT_MIN;
       int secLarg = INT_MIN;
        while(n > 0){
            int dig = n % 10;
            if(dig > larg){
                secLarg = larg;
                larg = dig;
            }else if(dig > secLarg){
                secLarg = dig;
            }
            n/=10;
        }
        return larg*secLarg;
    }
};