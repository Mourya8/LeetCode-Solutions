class Solution {
public:

    vector<vector<int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};

    bool afDFS(vector<vector<int>>& heights, vector<vector<int>>& af, int x, int y, int m, int n) {
        if (af[x][y] != 0) return af[x][y] == 1;
        if (x == 0 || y == 0) return af[x][y] = 1;

        af[x][y] = -1; // Mark as visited with a temporary value
        for (int i = 0; i < 4; i++) {
            int newX = x + directions[i][0];
            int newY = y + directions[i][1];
            if (newX >= 0 && newX < m && newY >= 0 && newY < n && heights[x][y] >= heights[newX][newY]) {
                if (afDFS(heights, af, newX, newY, m, n)) {
                    return af[x][y] = 1;
                }
            }
        }

        return af[x][y] = 0;
    }

    bool pfDFS(vector<vector<int>>& heights, vector<vector<int>>& pf, int x, int y, int m, int n) {
        if (pf[x][y] != 0) return pf[x][y] == 1;
        if (x == m - 1 || y == n - 1) return pf[x][y] = 1;

        pf[x][y] = -1; // Mark as visited with a temporary value
        for (int i = 0; i < 4; i++) {
            int newX = x + directions[i][0];
            int newY = y + directions[i][1];
            if (newX >= 0 && newX < m && newY >= 0 && newY < n && heights[x][y] >= heights[newX][newY]) {
                if (pfDFS(heights, pf, newX, newY, m, n)) {
                    return pf[x][y] = 1;
                }
            }
        }

        return pf[x][y] = 0;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> pf(m, vector<int>(n, 0));
        vector<vector<int>> af(m, vector<int>(n, 0));
        vector<vector<int>> r;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                afDFS(heights, af, i, j, m, n);
                pfDFS(heights, pf, i, j, m, n);
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (af[i][j] == 1 && pf[i][j] == 1) {
                    r.push_back({i, j});
                }
            }
        }

        return r;
    }
};