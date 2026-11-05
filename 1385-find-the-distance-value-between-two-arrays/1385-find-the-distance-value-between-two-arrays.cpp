class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n = arr1.size();
        int m = arr2.size();

        int cnt = 0;
        
        for(int i = 0; i < n; i++){
            bool ok = false;
            for(int j = 0; j < m; j++){
                if(abs(arr1[i]-arr2[j]) <= d){
                    ok = true;
                    break;
                }
            }
            if(ok){
                cnt++;
            }
        }
        return n-cnt;
    }
};