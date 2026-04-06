// @leet imports start
using namespace std;
// @leet imports end

// @leet start
class Solution
{
public:
  int robotSim(vector<int>& commands, vector<vector<int>>& obstacles)
  {
    auto obs = obstacles | views::transform([](auto&& v) -> pair<int, int> {
                 return { v[0], v[1] };
               }) |
               ranges::to<set>();
    int ans = 0;
    int x = 0, y = 0, dx = 0, dy = 1;
    for (auto cmd : commands) {
      switch (cmd) {
        case -2:
          dy = exchange(dx, -dy);
          break;
        case -1:
          dx = exchange(dy, -dx);
          break;
        default:
          for (int i = 0; i < cmd; i++) {
            if (obs.contains({ x + dx, y + dy }))
              break;
            x += dx, y += dy;
          }
      }
      ans = max(ans, x * x + y * y);
    }
    return ans;
  }
};
// @leet end