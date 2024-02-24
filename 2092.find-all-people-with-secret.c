// @leet start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

static int
compare_meetings(void const* a, void const* b)
{
  return (*(int* const*)a)[2] - (*(int* const*)b)[2];
}

#define N ((size_t)100000)

static int
find(int x, int* parent)
{
  if (parent[x] != x)
    parent[x] = find(parent[x], parent);
  return parent[x];
}

static void
unite(int a, int b, int* parent, int* rank)
{
  int pa = find(a, parent), pb = find(b, parent);
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

int*
findAllPeople(int n,
              int** meetings,
              int meetings_size,
              int* meetingsColSize,
              int first_person,
              int* return_size)
{
  qsort(meetings, meetings_size, sizeof(int*), compare_meetings);

  int parent[N], rank[N] = { [0 ... N - 1] = 0 };
  for (int i = 0; i < n; ++i)
    parent[i] = i;

  unite(0, first_person, parent, rank);

  for (int i = 0; i < n; ++i)
    printf(" %d", parent[i]);
  printf("\n");

  for (int l = 0; l < meetings_size;) {
    int r = l + 1;
    while (r < meetings_size && meetings[l][2] == meetings[r][2])
      ++r;
    for (int i = l; i < r; ++i)
      unite(meetings[i][0], meetings[i][1], parent, rank);
    for (int i = l; i < r; ++i) {
      if (find(meetings[i][0], parent) != find(0, parent)) {
        parent[meetings[i][0]] = meetings[i][0];
        parent[meetings[i][1]] = meetings[i][1];
        rank[meetings[i][0]] = rank[meetings[i][1]] = 0;
      }
    }
    l = r;
  }

  int buf[N], l = 0;
  for (int i = 0; i < n; ++i)
    if (find(i, parent) == find(0, parent))
      buf[l++] = i;
  *return_size = l;
  int* ret = calloc(*return_size, sizeof *ret);
  memcpy(ret, buf, *return_size * sizeof *ret);
  return ret;
}
// @leet end