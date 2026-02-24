// @leet imports start
using namespace std;
// @leet imports end

// @leet start
class Solution
{
public:
  bool hasAllCodes(string s, int k)
  {
    if (s.size() < k)
      return false;
    unsigned x{};
    for (int i = 0; i < k; i++) {
      x <<= 1;
      x += s[i] == '1';
    }
    vector<bool> f(1 << k);
    f[x] = true;
    for (int i = k; i < s.size(); i++) {
      x <<= 1;
      x += s[i] == '1';
      x &= (1 << k) - 1;
      f[x] = true;
    }
    return ranges::all_of(f, identity{});
  }
};
// @leet end