// @leet start
bool
halvesAreAlike(char* s)
{
  int n = 0, v = 0;
  for (int i = 0; s[i]; ++i) {
    char c = s[i] | 0x20;
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
      ++v;
    ++n;
  }
  int h = 0;
  for (int i = 0; i < n / 2; ++i) {
    char c = s[i] | 0x20;
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
      ++h;
  }
  return h + h == v;
}
// @leet end