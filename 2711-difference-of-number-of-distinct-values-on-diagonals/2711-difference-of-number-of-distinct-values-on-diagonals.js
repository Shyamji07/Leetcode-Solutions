/**
 * @param {number[][]} grid
 * @return {number[][]}
 */
var differenceOfDistinctValues = function(grid) {
    let ans = [];
        for (let i = 0; i < grid.length; i++) {
            ans[i] = [];
            for (let j = 0; j < grid[0].length; j++) {
                let a = new Set();
                let b = new Set();
                for (let k = 1; i - k >= 0 && j - k >= 0; k++) {
                    a.add(grid[i - k][j - k]);
                }
                for (let k = 1; i + k < grid.length && j + k < grid[0].length; k++) {
                    b.add(grid[i + k][j + k]);
                }
                ans[i][j] = Math.abs(a.size - b.size);
            }
        }
        return ans;
};