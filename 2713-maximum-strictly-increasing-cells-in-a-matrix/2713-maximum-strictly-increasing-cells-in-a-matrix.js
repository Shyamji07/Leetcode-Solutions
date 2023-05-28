const stmkey_in = (m) => new Map([...m].sort((x, y) => x[0] - y[0]));

const maxIncreasingCells = (g) => {
    let n = g.length, m = g[0].length, ma = new Map(),
        row = new Int32Array(n).fill(0), col = new Int32Array(m).fill(0), res = 0;
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            if (!ma.has(g[i][j])) ma.set(g[i][j], []);
            ma.get(g[i][j]).push([i, j]);
        }
    }
    ma = stmkey_in(ma);
    for (const [x, d] of ma) {
        let trow = [], tcol = [];
        for (const [i, j] of d) {
            let t = Math.max(1, row[i] + 1, col[j] + 1);
            res = Math.max(res, t);
            trow.push([i, t]);
            tcol.push([j, t]);
        }
        for (const [i, j] of trow) row[i] = Math.max(row[i], j);
        for (const [i, j] of tcol) col[i] = Math.max(col[i], j);
    }
    return res;
};