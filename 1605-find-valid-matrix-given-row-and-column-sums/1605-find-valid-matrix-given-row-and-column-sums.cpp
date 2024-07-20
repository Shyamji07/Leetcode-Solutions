class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum,vector<int>& colSum) {
        int N = rowSum.size();
        int M = colSum.size();

        vector<vector<int>> origMatrix(N, vector<int>(M, 0));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                origMatrix[i][j] = min(rowSum[i], colSum[j]);

                rowSum[i] -= origMatrix[i][j];
                colSum[j] -= origMatrix[i][j];
            }
        }

        return origMatrix;
    }
};