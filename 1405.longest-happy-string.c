// @leet start
#define swap(a, b)                                                            \
  {                                                                           \
    __typeof__(a) _t = (a);                                                   \
    (a) = (b);                                                                \
    (b) = _t;                                                                 \
  }

char*
longestDiverseString(int a, int b, int c)
{
  struct
  {
    char c;
    int n;
  } d[3] = { { .c = 'a', .n = a },
             { .c = 'b', .n = b },
             { .c = 'c', .n = c } };

  if (d[0].n < d[1].n)
    swap(d[0], d[1]);
  if (d[0].n < d[2].n)
    swap(d[0], d[2]);

  char* ret = malloc(a + b + c + 1);
  int i = 0;

  while (d[0].n > 0) {
    int j = d[1].n >= d[2].n ? 1 : 2;
    if (i < 2 || ret[i - 2] != d[0].c || ret[i - 1] != d[0].c) {
      ret[i++] = d[0].c;
      --d[0].n;
      if (d[0].n < d[j].n)
        swap(d[0], d[j]);
    } else {
      if (d[j].n == 0)
        break;
      ret[i++] = d[j].c;
      --d[j].n;
    }
  }

  ret[i] = 0;
  return ret;
}
// @leet end