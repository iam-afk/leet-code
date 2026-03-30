// @leet imports start
using namespace std;
// @leet imports end

// @leet start
class Solution
{
public:
  bool checkStrings(string s1, string s2)
  {
    array<array<int, 26>, 2> a{}, b{};
    for (int i = 0; i < s1.length(); i++) {
      a[i & 1][s1[i] - 'a']++;
      b[i & 1][s2[i] - 'a']++;
    }
    return a == b;
  }
};
// @leet end