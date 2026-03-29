Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
 

Example 1:


Input: board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true
Example 2:

Input: board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.


// solution：

// column scan lo, then horizontal scan
// use set for duplicate detection
// for 9*9,  (r / 3) * 3 + (c / 3)
/*

Row index (r) ↓
Col index (c) →

   0 1 2 | 3 4 5 | 6 7 8
   ------+-------+------
0 | 0 0 0 | 1 1 1 | 2 2 2
1 | 0 0 0 | 1 1 1 | 2 2 2
2 | 0 0 0 | 1 1 1 | 2 2 2
   ------+-------+------
3 | 3 3 3 | 4 4 4 | 5 5 5
4 | 3 3 3 | 4 4 4 | 5 5 5
5 | 3 3 3 | 4 4 4 | 5 5 5
   ------+-------+------
6 | 6 6 6 | 7 7 7 | 8 8 8
7 | 6 6 6 | 7 7 7 | 8 8 8
8 | 6 6 6 | 7 7 7 | 8 8 8

*/

#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> seen;

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                char num = board[r][c];

                if (num == '.') 
                {
                    continue;
                }

                string rowKey = "row" + to_string(r) + num;
                string colKey = "col" + to_string(c) + num;
                string boxKey = "box" + to_string((r / 3) * 3 + (c / 3)) + num;

                if (seen.count(rowKey) || seen.count(colKey) || seen.count(boxKey)) {
                    return false;
                }

                seen.insert(rowKey);
                seen.insert(colKey);
                seen.insert(boxKey);
            }
        }

        return true;
    }
};