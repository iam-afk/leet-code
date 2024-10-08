// @leet start
int
minSwaps(char* s)
{
  int ans = 0;
  int l = 0, r = 0;
  for (int i = 0; s[i]; ++i) {
    if (s[i] == '[')
      ++l;
    else
      ++r;
    if (l < r) {
      ++l, --r;
      ++ans;
    }
  }
  return ans;
}
// @leet end