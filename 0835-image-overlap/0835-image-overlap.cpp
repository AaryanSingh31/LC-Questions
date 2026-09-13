class Solution {
public:
    int abc(vector<vector<int>>& A, vector<vector<int>>& B, int rOff, int cOff){
        int n = A.size(), cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int bi = i+rOff;
                int bj = j+cOff;

                if((bi < 0 || bi >= n) || (bj < 0 || bj >= n)){
                    continue;
                }
                if(A[i][j] == 1 && B[bi][bj] == 1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size();
        int maxOv = 0;

        for(int rOff = -n+1; rOff < n; rOff++){
            for(int cOff = -n+1; cOff < n; cOff++){
                int cnt = 0;
                cnt = abc(A, B , rOff, cOff);

                maxOv = max(maxOv, cnt);
            }
        }
        return maxOv;
    }
};