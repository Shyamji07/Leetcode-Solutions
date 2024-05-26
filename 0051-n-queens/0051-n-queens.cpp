class Solution {
    // Time Complexity: O(N!)  First row has N choices second row has N-1 choices then N-2 and so on.... which is N!
    // Auxiliary Space: O(N^2) //Board space
public:
   vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> vec;
        vector<string> board(n,string(n,'.')); // Inititally filled with all '.'
        recurse(vec,board,0,n);
        return vec;
    }
    void recurse(vector<vector<string>> &vec,vector<string> & board,int row,int &n) 
    {        
        if(row == n) // Base case
        {
            vec.push_back(board);
            return;
        }
        for(int col=0;col<n;++col) // Filling columns one by one
        {
            if(isValid(board,row,col,n))
            {
                board[row][col] = 'Q';
                recurse(vec,board,row+1,n); // Recursing row by row
                board[row][col] = '.'; // Backtracking by removing queen from the cell to explore other choices
            }
        }
    }
    bool isValid(vector<string> &board,int row,int col,int n)
    {    
        for(int i=0;i<row;++i) // If column has queen already
        {
            if(board[i][col] == 'Q')
                return false;
        } 
		
        // If left diagonals have queen already 
        for(int i=1;row-i>=0&&col-i>=0;++i)
        {
            if(board[row-i][col-i] == 'Q')
                return false;
        }
        
        // If right diagonal have queen already
        for(int i=1;row-i>=0&&col+i<n;++i)
        {
            if(board[row-i][col+i] == 'Q')
                return false;
        }
		//We are not checking for rows as we are filling them one after the other
        return true;
    }
};