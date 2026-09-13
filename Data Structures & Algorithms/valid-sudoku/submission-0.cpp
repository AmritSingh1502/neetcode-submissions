class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = {false};
        bool cols[9][9] = {false};
        bool boxes[9][9] = {false};

        for(int r = 0; r < 9 ; r++){
            for( int c = 0 ; c < 9 ; c++){
                if(board[r][c]== '.') {
                    continue;
                }

                // convert char to int
                int val = board[r][c] - '1';

                // calculate which 3 * 3 box we are currently inside (0-8)
                int boxIdx = (r/3) * 3 + (c/3);

                //if we've already seen this digit in the current row , col or box
                if(rows[r][val] || cols[c][val] || boxes[boxIdx][val]) return false;

                // mark the digit as seen
                rows[r][val] = true;
                cols[c][val] = true;
                boxes[boxIdx][val]= true;
            }
        }
        return true;

        // time compexity : O(n^2)
        // space complexity : O(n^2)
    }
};
