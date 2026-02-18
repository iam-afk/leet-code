// @leet imports start
using namespace std;
// @leet imports end

// @leet start
class Solution
{
public:
  bool hasAlternatingBits(int n)
  {
    unsigned x{ 1 };
    while (2 * x < n)
      x = (x << 2) + 1;
    return x == n || 2 * x == n;
  }
};
// @leet end