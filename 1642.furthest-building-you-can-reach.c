// @leet start
static void
swap(int* a, int i, int j)
{
  int t = a[i];
  a[i] = a[j];
  a[j] = t;
}

static void
sift_down(int* a, int n, int i)
{

  while (2 * i + 1 < n) {
    int l = 2 * i + 1, r = 2 * i + 2;
    int j = l;
    if (r < n && a[r] < a[l])
      j = r;
    if (a[i] < a[j])
      break;
    swap(a, i, j);
    i = j;
  }
}

static void
sift_up(int* a, int i)
{
  while (a[i] < a[(i - 1) / 2]) {
    swap(a, i, (i - 1) / 2);
    i = (i - 1) / 2;
  }
}

#define N ((size_t)1e5)

int
furthestBuilding(int* heights, int heights_size, int bricks, int ladders)
{
  int a[N], n = 0, i;
  for (i = 0; i < heights_size - 1; ++i) {
    if (heights[i] >= heights[i + 1])
      continue;
    int d = heights[i + 1] - heights[i];
    a[n++] = d;
    sift_up(a, n - 1);
    if (n > ladders) {
      swap(a, 0, --n);
      sift_down(a, n, 0);
      bricks -= a[n];
      if (bricks < 0)
        break;
    }
  }
  return i;
}
// @leet end