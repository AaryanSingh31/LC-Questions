class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> directions {
            {0, 1}, //east
            {1, 0}, //south
            {0, -1}, //west
            {-1, 0}  //north
        };

        vector<vector<int>> ans;
        int steps = 0; //how much steps in each direction
        int dir = 0; //in which direction index of directions

        ans.push_back({rStart, cStart});
        while(ans.size() < rows * cols){
            if(dir == 0 || dir == 2){
                steps++;
            }
            for(int cnt = 0; cnt < steps; cnt++){
                rStart += directions[dir][0];
                cStart += directions[dir][1];

                //check if the cell is valid or not
                if(rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols){
                    ans.push_back({rStart, cStart});
                }
            }
            dir = (dir+1) % 4;
        }
        return ans;
    }
};