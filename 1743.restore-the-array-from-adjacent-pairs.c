/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int*
restoreArray(int** adjacent_pairs,
             int adjacent_pairs_size,
             int* adjacent_pairs_col_size,
             int* return_size)
{
#define N 100000
  int p1[2 * N + 1] = { [0 ... 2 * N] = INT_MIN }, p2[2 * N + 1] = { [0 ... 2 * N] = INT_MIN };
  for (int i = 0; i < adjacent_pairs_size; ++i) {
    int n1 = adjacent_pairs[i][0], n2 = adjacent_pairs[i][1];
    (p1[n1 + N] == INT_MIN ? p1 : p2)[n1 + N] = n2;
    (p1[n2 + N] == INT_MIN ? p1 : p2)[n2 + N] = n1;
  }
  int i, p = INT_MIN;
  for (i = 0; i <= 2 * N; ++i)
    if ((p1[i] == INT_MIN) != (p2[i] == INT_MIN))
      break;
  *return_size = adjacent_pairs_size + 1;
  int* array = calloc(*return_size, sizeof *array);
  for (int j = 0; j < *return_size; ++j) {
    array[j] = i - N;
    i = N + (p1[i] != p && p1[i] != INT_MIN ? p1[i] : p2[i]);
    p = array[j];
  }
  return array;
}