class MedianFinder {
public:
    priority_queue<int>p;
    priority_queue<int,vector<int>,greater<int>>q;
    MedianFinder() {
    }
    void addNum(int num) {
        int l=p.size(),r=q.size();
        if(l==0){ //case1
            p.push(num);
        }
        else if(l==r){//case2
            if(num<q.top())p.push(num);
            else{
                p.push(q.top());
                q.pop();
                q.push(num);
            }
        }
        else{  //case3
                if(num>=p.top())q.push(num);
                else{
                    q.push(p.top());
                    p.pop();
                    p.push(num);
                }
        }
    }
    
    double findMedian() {
         int l=p.size(),r=q.size();
        if(l>r){
            return double(p.top());
        }
        else return (double(p.top())+double(q.top()))/2;
    }
};

/*


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int ROWS = 20;
const int COLS = 10;

class Tetris {
public:
    Tetris(int rows, int cols) : rows(rows), cols(cols) {
        board = vector<vector<int>>(rows, vector<int>(cols, 0));
    }

    void placeBlock(vector<pair<int, int>>& block, int row, int col) {
        for (const auto& [dr, dc] : block) {
            board[row + dr][col + dc] = 1;
        }
    }

    void removeBlock(vector<pair<int, int>>& block, int row, int col) {
        for (const auto& [dr, dc] : block) {
            board[row + dr][col + dc] = 0;
        }
    }

    bool canPlaceBlock(vector<pair<int, int>>& block, int row, int col) {
        for (const auto& [dr, dc] : block) {
            int nr = row + dr;
            int nc = col + dc;
            if (nr < 0 || nr >= rows || nc < 0 || nc >= cols || board[nr][nc] == 1) {
                return false;
            }
        }
        return true;
    }

    int calculateScore() {
        int score = 0;
        for (int i = 0; i < rows; ++i) {
            if (isRowFull(i)) {
                score++;
                clearRow(i);
            }
        }
        return score;
    }

    void printBoard() {
        for (const auto& row : board) {
            for (int cell : row) {
                cout << (cell ? "#" : ".");
            }
            cout << endl;
        }
    }

private:
    int rows, cols;
    vector<vector<int>> board;

    bool isRowFull(int row) {
        for (int i = 0; i < cols; ++i) {
            if (board[row][i] == 0) {
                return false;
            }
        }
        return true;
    }

    void clearRow(int row) {
        for (int i = 0; i < cols; ++i) {
            board[row][i] = 0;
        }
        // Move all rows above down by one
        for (int i = row; i > 0; --i) {
            board[i] = board[i - 1];
        }
        board[0] = vector<int>(cols, 0);
    }
};

vector<pair<int, int>> getShape(int shapeType) {
    // Return the coordinates of the block relative to its top-left corner
    if (shapeType == 1) {
        // Square
        return {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    } else if (shapeType == 2) {
        // Rectangle (3x2)
        return {{0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2}};
    } else if (shapeType == 3) {
        // L-shape
        return {{0, 0}, {1, 0}, {2, 0}, {2, 1}};
    }
    return {};
}

int main() {
    Tetris game(ROWS, COLS);

    vector<vector<int>> queries = {
        {1, 0, 0, 1},
        {1, 2, 0, 2},
        {1, 4, 0, 3},
        {2, 0, 0, 2}
    };

    for (const auto& query : queries) {
        if (query[0] == 1) {
            int row = query[1];
            int col = query[2];
            int shapeType = query[3];
            vector<pair<int, int>> shape = getShape(shapeType);
            if (game.canPlaceBlock(shape, row, col)) {
                game.placeBlock(shape, row, col);
                cout << "Placed block type " << shapeType << " at (" << row << ", " << col << ")\n";
            } else {
                cout << "Cannot place block type " << shapeType << " at (" << row << ", " << col << ")\n";
            }
        } else if (query[0] == 2) {
            // Calculate the score and print the board
            int score = game.calculateScore();
            cout << "Score: " << score << endl;
            game.printBoard();
        }
    }

    return 0;
}


*/
