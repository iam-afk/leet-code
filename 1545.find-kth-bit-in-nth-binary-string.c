// @leet start
char
findKthBit(int n, int k)
{
  int r = 1;
  for (int i = 1; i < n; ++i)
    r = 2 * r + 1;
  bool inv = false;
  while (r > 1) {
    int m = r / 2 + 1;
    if (k == m) {
      inv = !inv;
      break;
    }
    if (k > m) {
      inv = !inv;
      k = r - k + 1;
    }
    r = m - 1;
  }
  return inv ? '1' : '0';
}
// @leet end