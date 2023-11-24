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
    if (r < n && a[r] > a[l])
      j = r;
    if (a[i] > a[j])
      break;
    swap(a, i, j);
    i = j;
  }
}

static void
sift_up(int* a, int i)
{
  while (a[i] > a[(i - 1) / 2]) {
    swap(a, i, (i - 1) / 2);
    i = (i - 1) / 2;
  }
}

static int
pop(int* a, int* n)
{
  --*n;
  swap(a, 0, *n);
  sift_down(a, *n, 0);
  return a[*n];
}

int
maxCoins(int* piles, int piles_size)
{
  for (int i = piles_size / 2 - 1; i >= 0; --i)
    sift_down(piles, piles_size, i);
  int answer = 0;
  int n = piles_size / 3;
  for (int i = 0; i < n; ++i) {
    pop(piles, &piles_size);
    answer += pop(piles, &piles_size);
  }
  return answer;
}