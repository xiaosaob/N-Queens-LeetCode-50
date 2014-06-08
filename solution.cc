// The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



// Given an integer n, return all distinct solutions to the n-queens puzzle.

// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

// For example,
// There exist two distinct solutions to the 4-queens puzzle:

// [
//  [".Q..",  // Solution 1
//   "...Q",
//   "Q...",
//   "..Q."],

//  ["..Q.",  // Solution 2
//   "Q...",
//   "...Q",
//   ".Q.."]
// ]

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > res;
        vector<string> sol(n, string(n, '.'));
        helper(n, 0, sol, res);
        return res;
    }
    
    void helper(int n, int row, vector<string> &sol, vector<vector<string> > &res) {
        if(row == n) {
            res.push_back(sol);
            return;
        }
        
        for(int col = 0; col < n; ++col) {
            if(check(row,col,sol)) {
                sol[row][col] = 'Q';
                helper(n, row+1, sol, res);
                sol[row][col] = '.';
            }
        }
    }
    
    bool check(int row, int col, const vector<string> &sol) {
        int n = sol.size();
        for(int i = -1; i <= 1; ++i) {
            for(int j = -1; j <= 1; ++j) {
                if(i == 0 && j == 0) continue;
                int curRow = row, curCol = col;
                while(curRow >= 0 && curRow < n && curCol >= 0 && curCol < n) {
                    if(sol[curRow][curCol] == 'Q') return false;
                    curRow += i;
                    curCol += j;
                }
            }
        }
        return true;
    }
    
};
