class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int BOARD_SIZE = 9;

        // rows
        for (int row = 0; row < BOARD_SIZE; row++) {
            unordered_set<int> items = {}; 
            for (int col = 0; col < BOARD_SIZE; col++) {
                if (board[row][col] == '.') continue;
                if (items.find(board[row][col]) != items.end()) {
                    cout << "bad row " << row;
                    return false;
                }
                items.insert(board[row][col]);
            } 
        }

        // cols
        for (int col = 0; col < BOARD_SIZE; col++) {
            unordered_set<int> items = {}; 
            for (int row = 0; row < BOARD_SIZE; row++) {
                if (board[row][col] == '.') continue;
                if (items.find(board[row][col]) != items.end()) {
                    cout << "bad col " << col;
                    return false;
                }
                items.insert(board[row][col]);
            } 
        }

        // sub-boxes
        for (int box = 0; box < 9; box++) {
            int start_row = (box / 3) * 3;
            int start_col = (box % 3) * 3;
            unordered_set<int> items = {}; 
            for (int row = start_row; row < start_row + 3; row++) {
                for (int col = start_col; col < start_col + 3; col++) {
                    if (board[row][col] == '.') continue;
                    if (items.find(board[row][col]) != items.end()) {
                        cout << "bad box " << box << " " << board[row][col];
                        return false;
                    }
                    items.insert(board[row][col]);
                } 
            }
        }

        return true;
    }
};
