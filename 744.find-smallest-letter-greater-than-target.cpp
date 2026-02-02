// @leet imports start
#include <algorithm>
using namespace std;
// @leet imports end

// @leet start
class Solution
{
public:
  char nextGreatestLetter(vector<char>& letters, char target)
  {
    if (auto it = ranges::upper_bound(letters, target); it != letters.end())
      return *it;
    return letters.front();
  }
};
// @leet end