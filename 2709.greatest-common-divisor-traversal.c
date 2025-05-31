// @leet start
#define max(a, b)                                                             \
  ({                                                                          \
    __typeof__(a) _a = (a);                                                   \
    __typeof__(b) _b = (b);                                                   \
    _a > _b ? _a : _b;                                                        \
  })

#define N ((size_t)100000)

static int
find(int x, int* parent)
{
  return parent[x] == x ? x : (parent[x] = find(parent[x], parent));
}

static void
unite(int a, int b, int* parent, int* rank)
{
  int pa = find(a, parent);
  int pb = find(b, parent);
  if (pa == pb)
    return;
  if (rank[pa] > rank[pb])
    parent[pb] = pa;
  else if (rank[pa] < rank[pb])
    parent[pa] = pb;
  else {
    parent[pb] = pa;
    ++rank[pa];
  }
}

bool
canTraverseAllPairs(int* nums, int nums_size)
{
  if (nums_size == 1)
    return true;

  int mx = 0;
  for (int i = 0; i < nums_size; ++i) {
    if (nums[i] == 1)
      return false;
    mx = max(mx, nums[i]);
  }

  int primes[N + 1], n = 0;
  int sieve[N + 1] = { 0 };
  for (int d = 2; d <= mx; ++d)
    if (sieve[d] == 0) {
      primes[d] = n++;
      for (int x = d; x <= mx; x += d)
        sieve[x] = d;
    }

  int parent[9592], rank[9592] = { 0 };
  for (int i = 0; i < n; ++i)
    parent[i] = i;
  bool used[9592] = { false };

  for (int i = 0; i < nums_size; ++i) {
    int x = nums[i], r = primes[sieve[x]];
    while (x > 1) {
      int p = sieve[x];
      used[primes[p]] = true;
      unite(r, primes[p], parent, rank);
      while (x % p == 0)
        x /= p;
    }
  }

  int count = 0;
  for (int i = 0; i < n; ++i)
    if (used[i] && find(i, parent) == i)
      ++count;

  return count == 1;
}
// @leet end