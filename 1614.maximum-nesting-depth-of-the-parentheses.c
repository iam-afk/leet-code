// @leet start
#define max(a, b)                                                                                  \
  ({                                                                                               \
    __typeof__(a) _a = (a);                                                                        \
    __typeof__(b) _b = (b);                                                                        \
    _a > _b ? _a : _b;                                                                             \
  })

int
maxDepth(char* s)
{
  int md = 0;
  for (int d = 0; *s; ++s) {
    if (*s == '(')
      ++d;
    else if (*s == ')')
      --d;
    md = max(md, d);
  }
  return md;
}
// @leet end