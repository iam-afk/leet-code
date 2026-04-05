// @leet imports start
using namespace std;
// @leet imports end

// @leet start
class Solution
{
public:
  bool judgeCircle(string moves)
  {
    int x{}, y{};
    for (auto c : moves) {
      x -= c == 'L';
      x += c == 'R';
      y -= c == 'U';
      y += c == 'D';
    }
    return x == 0 && y == 0;
  }
};
// @leet end