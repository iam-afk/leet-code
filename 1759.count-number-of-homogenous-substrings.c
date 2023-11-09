#define M (uint64_t)(1e9 + 7)

int
countHomogenous(char* s)
{
  uint64_t a = 0, n = 1;
  char c = *s++;
  do {
    if (*s == c)
      ++n;
    else {
      a += (n + 1) * n / 2 % M;
      n = 1;
    }
  } while ((c = *s++) != 0);
  return a;
}