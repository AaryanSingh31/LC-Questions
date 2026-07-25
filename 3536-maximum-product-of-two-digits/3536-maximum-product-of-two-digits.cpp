class Solution {
public:
    int maxProduct(int n) {
       int larg = INT_MIN;
       int secLarg = INT_MIN;
        while(n > 0){
            int dig = n % 10;
            if(dig > larg){ //if curr dig is larger than the largest dig
                secLarg = larg;
                larg = dig;
            }else if(dig > secLarg){ //if curr dig is smaller than largest but larger than sec largest
                secLarg = dig;
            }
            n/=10;
        }
        return larg*secLarg;
    }
};