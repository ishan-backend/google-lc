class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> res;

        int i = rStart, j = cStart;
        int di = 0, dj = 1; // direction = right initially (0, 1, -1)
        int twice = 2; // counter to track change in direction
        int moves = 1; // no of steps to move in current direction
        int next_moves = 2; // no of steps to move after changing direction twice

        while(res.size() < rows*cols) {
            if(-1 < i  and i < rows and -1 < j and j < cols) {
                res.push_back({i, j});
            }

            i += di;
            j += dj;
            moves -= 1;
            if(moves == 0) { // time to change direction
                // 90 deg clockwise turn
                int temp = di;
                di = dj;
                dj = -temp;

                twice -= 1;
                if(twice == 0) {
                    // turned 180 deg
                    // next moves has to be assigned to moves
                    twice = 2; // reset twice
                    moves = next_moves;
                    next_moves += 1;
                } else {
                    // when twice = 1
                    // reassign the value of moves
                    moves = next_moves-1;
                }

            }
        }

        return res;
    }
};