#define max(a, b)                                                                                  \
  ({                                                                                               \
    __typeof__(a) _a = (a);                                                                        \
    __typeof__(b) _b = (b);                                                                        \
    _a > _b ? _a : _b;                                                                             \
  })

int
largestSubmatrix(int** matrix, int matrix_size, int* matrix_col_size)
{
  int m = matrix_size, n = matrix_col_size[0];

  typedef struct
  {
    int height, index;
  } height_t;
  height_t heights[100000];
  int heights_len = 0;
  bool column_in_heights[100000];

  int answer = 0;
  for (int i = 0; i < m; ++i) {
    memset(column_in_heights, 0, n * sizeof(bool));
    int next_heights_len = 0;
    for (int j = 0; j < heights_len; ++j) {
      if (matrix[i][heights[j].index] == 1)
        heights[next_heights_len++] =
          (height_t){ .height = heights[j].height + 1, .index = heights[j].index };
      column_in_heights[heights[j].index] = true;
    }
    for (int j = 0; j < n; ++j)
      if (!column_in_heights[j] && matrix[i][j] == 1) {
        heights[next_heights_len++] = (height_t){ .height = 1, .index = j };
      }
    heights_len = next_heights_len;

    for (int j = 0; j < heights_len; ++j) {
      answer = max(answer, heights[j].height * (j + 1));
    }
  }
  return answer;
}