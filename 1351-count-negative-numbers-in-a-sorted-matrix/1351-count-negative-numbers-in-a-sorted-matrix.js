var countNegatives = function(grid) {
    let count = 0;
    const n = grid[0].length;
    for (const row of grid) {
        let left = 0, right = n - 1;
        while (left <= right) {
            const mid = Math.floor((right + left) / 2);
            if (row[mid] < 0) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        count += n - left;
    }
    return count;
};