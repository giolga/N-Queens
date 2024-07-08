#include <vector>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int cnt = 0;
    vector<int> board;
    vector<vector<string>> solutions;

    vector<vector<string>> solveNQueens(int n) {
        board.resize(n + 1);
        start(1, n);
        return solutions;
    }

    void draw(int n) {
        vector<string> solution;
        for(int i = 1; i <= n; i++) {
            string row;
            for(int j = 1; j <= n; j++) {
                if (board[j] == i)
                    row += "Q";
                else 
                    row += ".";
            }
            solution.push_back(row);
        }
        solutions.push_back(solution);
    }

    bool danger(int row, int col) {
        for(int i = 1; i < col; i++) {
            int previusColumn = i;
            int previusRow = board[i];

            if(row == previusRow || abs(row - previusRow) == abs(col - previusColumn))
                return true;
        }

        return false;
    }

    void start(int col, int n) {
        if(col > n) {
            draw(n);
            cnt++;
        }
        else {
            for(int row = 1; row <= n; row++) {
                if(!danger(row, col)) {
                    board[col] = row;
                    start(col + 1, n);
                }
            }
        }
    }
};
