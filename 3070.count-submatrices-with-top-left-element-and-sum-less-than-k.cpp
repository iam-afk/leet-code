// @leet imports start
using namespace std;
// @leet imports end

// @leet start
class Solution
{
public:
  int countSubmatrices(vector<vector<int>>& grid, int k)
  {
    int ans{}, m = grid[0].size();
    vector<int> p(m + 1);
    for (auto& row : grid) {
      vector<int> d;
      d.reserve(p.size());
      d.push_back(0);
      for (int i = 0; d[i] <= k && i < p.size() - 1; i++)
        d.push_back(d[i] + row[i] - p[i] + p[i + 1]);
      if (d.back() > k)
        d.pop_back();
      ans += d.size() - 1;
      p = std::move(d);
    }
    return ans;
  }
};
// @leet end