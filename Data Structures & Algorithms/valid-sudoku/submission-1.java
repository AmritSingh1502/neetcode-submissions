class Solution {
    public boolean isValidSudoku(char[][] board) {
        boolean[][]rows = new boolean[9][10];
        boolean[][] cols = new boolean[9][10];
        boolean[][] boxes = new boolean[9][10];

        for( int r = 0 ; r < 9 ; r++){
            for(int c = 0 ; c < 9 ; c++){
                char ch = board[r][c];
                 if(ch == '.') continue;

                 int digit = ch - '0';
                 int boxIndex = (r/3) * 3 + (c/3);

                 if(rows[r][digit] || cols[c][digit] || boxes[boxIndex][digit]){
                    return false;
                 }

                 rows[r][digit]= true;
                 cols[c][digit] = true;
                 boxes[boxIndex][digit] = true;
            }
        }
        return true;
    }
}
