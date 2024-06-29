#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  void dfs(vector<vector<int>> &grid, int row, int col,
           vector<vector<bool>> &vis, vector<pair<int, int>> &v, int row0,
           int col0) {
    v.push_back({row-row0, col-col0});
    vis[row][col] = true;
    int n = grid.size();
    int m = grid[0].size();
    int dlrow[] = {-1, 0, 1, 0};
    int dlcol[] = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++) {
      int nrow = row + dlrow[i];
      int ncol = col + dlcol[i];
      if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] &&
          grid[nrow][ncol] == 1) {
        dfs(grid, nrow, ncol, vis, v, row0, col0);
      }
    }
  }
public:
  int countDistinctIslands(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    set<vector<pair<int, int>>> s;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 1 && !vis[i][j]) {
          vector<pair<int, int>> v;
          dfs(grid, i, j, vis, v, i, j);
          s.insert(v);
        }
      }
    }
    return s.size();
  }
};