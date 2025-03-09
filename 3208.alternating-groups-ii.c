// @leet start
int
numberOfAlternatingGroups(int* colors, int colorsSize, int k)
{
  int ans = 0, a = 1, p = colors[0];
  for (int i = 1; i < colorsSize; p = colors[i++])
    if (colors[i] != p)
      ++a;
    else {
      ans += (a >= k) * (a - k + 1);
      a = 1;
    }
  for (int i = 0; i < k; p = colors[i++])
    if (colors[i] != p)
      ++a;
    else {
      ans += (a >= k) * (a - k + 1);
      a = 1;
    }
  ans += (a >= k) * (a - k);
  return ans;
}
// @leet end