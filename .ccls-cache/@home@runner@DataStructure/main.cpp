#include <queue>
#include <vector>
using namespace std;
class Solution {
private:
  void BFS(vector<vector<char>> &grid, int row, int column,
           vector<vector<bool>> &vis) {
    vis[row][column] = true;
    int n = grid.size();
    int m = grid[0].size();
    int dlrow[] = {-1, 0, 1, 0};
    int dlcol[] = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++) {
      int nrow = row + dlrow[i];
      int ncol = column + dlcol[i];
      if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol]) {
        BFS(grid, nrow, ncol, vis);
      }
    }
  }

public:
  // return no of islands
  int numIslands(vector<vector<char>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    int count = 0;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == '1') {
          q.push({i, j});
        }
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == '1' && !vis[i][j]) {
          BFS(grid, i, j, vis);
          count++;
        }
      }
    }
    return count;
  }
};
