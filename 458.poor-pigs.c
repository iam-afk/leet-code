int
poorPigs(int buckets, int minutesToDie, int minutesToTest)
{
  int i = 0;
  int t = minutesToTest / minutesToDie + 1;
  for (int r = 1; r < buckets; ++i)
    r *= t;
  return i;
}