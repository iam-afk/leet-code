int
minimumOneBitOperations(int n)
{
  int d0 = 0, d1 = 0;
  for (int i = 0; n > 0; ++i, n >>= 1) {
    int t[2];
    t[n & 1] = d0;
    t[1 - (n & 1)] = d1 + (1 << i);
    d0 = t[0], d1 = t[1];
  }
  return d0;
}