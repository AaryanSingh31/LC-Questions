class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0, num = 0;
        long long pow = 1;
        while(n > 0){
            int ld = n % 10;
            if(ld != 0){
                sum += ld;
                num = ld * pow + num;
                pow *= 10;
            }  
            n/=10;
        }

        return num * sum;
    }
};