int
countPalindromicSubsequence(char* s)
{
  size_t n = strlen(s);

  struct
  {
    int l, r;
  } index[26] = { [0 ... 25] = { -1, 0 } };

  for (int i = 0; s[i] != 0; ++i) {
    if (index[s[i] - 'a'].l < 0)
      index[s[i] - 'a'].l = i;
    index[s[i] - 'a'].r = i;
  }

  int a = 0;
  for (int i = 0; i < 26; ++i) {
    int x = 0;
    for (int j = index[i].l + 1; j < index[i].r; ++j)
      x |= 1 << (s[j] - 'a');
    a += __builtin_popcount(x);
  }
  return a;
}