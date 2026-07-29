// @leet imports start
using namespace std;
// @leet imports end

// @leet start
class Solution
{
public:
  vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k)
  {
    int n = grid.size(), m = grid.front().size();
    vector<vector<int>> ans = grid;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        int p = (i * m + j + k) % (n * m);
        ans[p / m][p % m] = grid[i][j];
      }
    return ans;
  }
};
// @leet end