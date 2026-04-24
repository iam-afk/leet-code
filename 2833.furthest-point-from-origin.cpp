// @leet imports start
using namespace std;
// @leet imports end

// @leet start
class Solution
{
public:
  int furthestDistanceFromOrigin(string moves)
  {
    int l{}, r{}, _{};
    for (auto c : moves) {
      l += c == 'L';
      r += c == 'R';
      _ += c == '_';
    }
    return abs(l - r) + _;
  }
};
// @leet end