// @leet imports start
using namespace std;
// @leet imports end

// @leet start
class Solution
{
public:
  bool canPartitionGrid(vector<vector<int>>& grid)
  {
    auto grid_sum = ranges::fold_left(grid | views::join, 0L, plus{});
    if (grid_sum % 2 != 0)
      return false;
    auto half = grid_sum / 2;

    vector<long> col_sum(grid.front().size());

    auto row_sum = 0L;
    for (auto& row : grid) {
      for (int j = 0; j < row.size(); j++) {
        col_sum[j] += row[j];
        row_sum += row[j];
      }
      if (row_sum == half)
        return true;
    }

    for (auto prefix_col_sum = 0L; auto sum : col_sum) {
      prefix_col_sum += sum;
      if (prefix_col_sum == half)
        return true;
    }

    return false;
  }
};
// @leet end