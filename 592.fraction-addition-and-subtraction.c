// @leet start

static int
gcd(int a, int b)
{
  if (b != 0) {
    a = a % b;
    return gcd(b, a);
  }
  return a;
}

char*
fractionAddition(char* expression)
{
  int ns[10], ds[10], n = 0;
  char* p = expression;
  for (; *p; ++n) {
    int sign = 1;
    if (*p == '-')
      ++p, sign = -1;
    if (*p == '+')
      ++p, sign = 1;
    ns[n] = ds[n] = 0;
    while (*p && isdigit(*p))
      ns[n] = ns[n] * 10 + *p++ - '0';
    ns[n] *= sign;
    ++p;
    while (*p && isdigit(*p))
      ds[n] = ds[n] * 10 + *p++ - '0';
  }
  int rn = 0, rd = 1;
  for (int i = 0; i < n; ++i)
    rd = rd / gcd(rd, ds[i]) * ds[i];
  for (int i = 0; i < n; ++i)
    rn += rd / ds[i] * ns[i];
  int k = abs(gcd(rn, rd));
  snprintf(expression, p - expression + 1, "%d/%d", rn / k, rd / k);
  return expression;
}
// @leet end