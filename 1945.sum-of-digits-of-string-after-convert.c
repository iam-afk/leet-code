// @leet start
int
getLucky(char* s, int k)
{
  int n = 0;
  for (int i = 0; s[i] != 0; ++i) {
    n += (s[i] - 'a' + 1) / 10;
    n += (s[i] - 'a' + 1) % 10;
  }
  for (int i = 1; i < k; ++i) {
    int m = 0;
    while (n > 0) {
      m += n % 10;
      n /= 10;
    }
    n = m;
  }
  return n;
}
// @leet end