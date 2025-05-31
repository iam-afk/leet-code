// @leet start
static int
compare_diff(void const* a, void const* b, void* c)
{
  int i = *(int const*)a, j = *(int const*)b;
  int* difficulty = c;
  return difficulty[i] - difficulty[j];
}

static int
compare_ints(void const* a, void const* b)
{
  return *(int const*)a - *(int const*)b;
}

#define max(a, b)                                                             \
  ({                                                                          \
    __typeof__(a) _a = (a);                                                   \
    __typeof__(b) _b = (b);                                                   \
    _a > _b ? _a : _b;                                                        \
  })

int
maxProfitAssignment(int* difficulty,
                    int difficulty_size,
                    int* profit,
                    int profitSize,
                    int* worker,
                    int worker_size)
{
  static int index[(size_t)1e4];
  for (int i = 0; i < difficulty_size; ++i)
    index[i] = i;
  qsort_r(index, difficulty_size, sizeof(int), compare_diff, difficulty);
  qsort(worker, worker_size, sizeof(int), compare_ints);

  int total_profit = 0, max_profit = 0;
  for (int i = 0, j = 0; j < worker_size; ++j) {
    for (; i < difficulty_size && difficulty[index[i]] <= worker[j]; ++i)
      max_profit = max(max_profit, profit[index[i]]);
    total_profit += max_profit;
  }

  return total_profit;
}
// @leet end