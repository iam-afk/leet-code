// @leet start

static int
compare_intervals(void const* lhs, void const* rhs)
{
  int *a = *(int* const*)lhs, *b = *(int* const*)rhs;
  if (a[1] != b[1])
    return (a[1] > b[1]) - (a[1] < b[1]);
  return (a[0] < b[0]) - (a[0] > b[0]);
}

int
intersectionSizeTwo(int** intervals, int intervalsSize, int* intervalsColSize)
{
  qsort(intervals, intervalsSize, sizeof *intervals, compare_intervals);
  int ans = 0, p1 = -1, p2 = -1;
  for (int i = 0; i < intervalsSize; ++i) {
    if (p2 < intervals[i][0])
      ans += 2, p1 = intervals[i][1] - 1, p2 = intervals[i][1];
    if (p1 < intervals[i][0])
      ans += 1, p1 = p2, p2 = intervals[i][1];
  }
  return ans;
}
// @leet end