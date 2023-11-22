
typedef struct
{
  int i, j;
} pos_t;

static int
compare_pos(void const* a, void const* b)
{
  pos_t const *pos_a = (pos_t*)a, *pos_b = (pos_t*)b;
  int k = pos_a->i + pos_a->j - pos_b->i - pos_b->j;
  if (k != 0)
    return k;
  return pos_b->i - pos_a->i;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int*
findDiagonalOrder(int** nums, int nums_size, int* nums_col_size, int* return_size)
{
  *return_size = 0;

  pos_t index[100000];
  for (int i = 0; i < nums_size; ++i)
    for (int j = 0; j < nums_col_size[i]; ++j)
      index[(*return_size)++] = (pos_t){ .i = i, .j = j };

  qsort(index, *return_size, sizeof(pos_t), compare_pos);

  int* answer = calloc(*return_size, sizeof *answer);

  for (int i = 0; i < *return_size; ++i)
    answer[i] = nums[index[i].i][index[i].j];

  return answer;
}