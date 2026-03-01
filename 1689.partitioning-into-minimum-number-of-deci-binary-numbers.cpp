// @leet imports start
using namespace std;
// @leet imports end

// @leet start
class Solution
{
public:
  int minPartitions(string n) { return *ranges::max_element(n) - '0'; }
};
// @leet end