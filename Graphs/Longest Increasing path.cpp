#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;

        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0)); // Memoization table
        int maxLen = 0;

        // Try DFS from each cell
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                maxLen = max(maxLen, dfs(matrix, dp, i, j, m, n));

        return maxLen;
    }

private:
    // Directions: up, down, left, right
    vector<int> dir = {-1, 0, 1, 0, -1};

    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j, int m, int n) {
        if (dp[i][j] != 0) return dp[i][j]; // already computed

        int maxPath = 1;

        for (int d = 0; d < 4; ++d) {
            int x = i + dir[d];
            int y = j + dir[d + 1];

            if (x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[i][j]) {
                maxPath = max(maxPath, 1 + dfs(matrix, dp, x, y, m, n));
            }
        }

        dp[i][j] = maxPath;
        return dp[i][j];
    }
};
