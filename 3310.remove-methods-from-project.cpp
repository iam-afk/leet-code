// @leet imports start
using namespace std;
// @leet imports end

// @leet start
class Solution
{
public:
  vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations)
  {
    vector<vector<int>> g(n, vector<int>{});
    for (auto& inv : invocations)
      g[inv.front()].push_back(inv.back());

    vector<bool> suspicious(n, false);
    [&](this auto&& self, int v) -> void {
      suspicious[v] = true;
      for (auto u : g[v])
        if (!suspicious[u])
          self(u);
    }(k);

    vector<int> ans;
    for (auto& inv : invocations)
      if (!suspicious[inv.front()] && suspicious[inv.back()]) {
        for (int i{}; i < n; i++)
          ans.push_back(i);
        return ans;
      }

    for (int i{}; i < n; i++)
      if (!suspicious[i])
        ans.push_back(i);
    return ans;
  }
};
// @leet end