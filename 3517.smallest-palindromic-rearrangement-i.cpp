// @leet imports start
using namespace std;
// @leet imports end

// @leet start
class Solution
{
public:
  string smallestPalindrome(string s)
  {
    int n = s.length();
    array<int, 26> a{};
    for (int i{}; i < n / 2; i++)
      a[s[i] - 'a']++;
    int l{}, r{ n - 1 };
    for (int i = 0; i < 26; i++)
      for (int j{}; j < a[i]; j++)
        s[l++] = s[r--] = 'a' + i;
    return s;
  }
};
// @leet end