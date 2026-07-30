// @leet imports start
using namespace std;
// @leet imports end

// @leet start
class Solution
{
public:
  int minimumPushes(string word)
  {
    int ans{};
    for (int i = 0; i < word.length(); ++i)
      ans += i / 8 + 1;
    return ans;
  }
};
// @leet end