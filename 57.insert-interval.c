// @leet start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
#define max(a, b)                                                             \
  ({                                                                          \
    __typeof__(a) _a = (a);                                                   \
    __typeof__(b) _b = (b);                                                   \
    _a > _b ? _a : _b;                                                        \
  })

#define N ((size_t)10000)

static int buf_col_sizes[N] = { [0 ... N - 1] = 2 };

int**
insert(int** intervals,
       int intervals_size,
       int* intervals_col_sizes,
       int* new_interval,
       int new_interval_size,
       int* ret_size,
       int** ret_col_sizes)
{
  int *buf_ret[N], size = 0;
  int i = 0;
  while (i < intervals_size && intervals[i][1] < new_interval[0])
    buf_ret[size++] = intervals[i++];
  if (i < intervals_size && intervals[i][0] <= new_interval[0])
    new_interval[0] = intervals[i][0];
  while (i < intervals_size && intervals[i][0] <= new_interval[1])
    new_interval[1] = max(new_interval[1], intervals[i++][1]);
  buf_ret[size++] = new_interval;
  while (i < intervals_size)
    buf_ret[size++] = intervals[i++];

  *ret_size = size;
  *ret_col_sizes = calloc(size, sizeof **ret_col_sizes);
  memcpy(*ret_col_sizes, buf_col_sizes, size * sizeof **ret_col_sizes);
  int** ret = calloc(size, sizeof *ret);
  memcpy(ret, buf_ret, size * sizeof *ret);
  return ret;
}
// @leet end