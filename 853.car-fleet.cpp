// @leet imports start
using namespace std;
// @leet imports end

// @leet start
class Solution
{
public:
  int carFleet(int target, vector<int>& position, vector<int>& speed)
  {
    int n = position.size();
    vector<int> idx(n);
    ranges::iota(idx, 0);
    ranges::sort(idx, greater<>{}, [&](auto i) { return position[i]; });

    auto faster = [&](int i, int j) {
      return (target - position[i]) / static_cast<float>(speed[i]) >=
             (target - position[j]) / static_cast<float>(speed[j]);
    };

    int p = -1, ans{};
    for (auto i : idx)
      if (p < 0 || !faster(p, i))
        p = i, ans++;

    return ans;
  }
};
// @leet end