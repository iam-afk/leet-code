// @leet start
#define M ((int)1e9 + 7)

static int
transform(char c, int t, int* d)
{
  if (t <= 'z' - c)
    return 1;
  t -= 'z' - c + 1;
  if (d[t])
    return d[t];
  d[t] = transform('a', t, d);
  d[t] += transform('b', t, d);
  d[t] %= M;
  return d[t];
}

int
lengthAfterTransformations(char* s, int t)
{
  int ans = 0;
  int d[100001] = {};
  for (int i = 0; s[i]; ++i) {
    ans += transform(s[i], t, d);
    ans %= M;
  }
  return ans;
}
// @leet end