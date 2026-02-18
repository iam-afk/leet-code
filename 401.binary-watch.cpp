// @leet imports start
using namespace std;
// @leet imports end

// @leet start
class Solution
{
public:
  vector<string> readBinaryWatch(int turnedOn)
  {
    vector<string> ans;
    for (unsigned h{}; h < 12; h++)
      for (unsigned m{}; m < 60; m++)
        if (popcount(h) + popcount(m) == turnedOn)
          ans.push_back(format("{}:{:02}", h, m));
    return ans;
  }
};
// @leet end