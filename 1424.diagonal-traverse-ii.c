/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int*
findDiagonalOrder(int** nums,
                  int nums_size,
                  int* nums_col_size,
                  int* return_size)
{
  *return_size = 0;
  for (int i = 0; i < nums_size; ++i)
    *return_size += nums_col_size[i];

  int* answer = calloc(*return_size, sizeof *answer);
  int last = 0;

  typedef struct
  {
    int i, j;
  } pos_t;
  pos_t queue[nums_size + 1];
  int front = 0, tail = 0, len = 0;

  queue[tail] = (pos_t){ .i = 0, .j = 0 };
  tail = (tail + 1) % (nums_size + 1), ++len;

  while (len > 0) {
    pos_t p = queue[front];
    front = (front + 1) % (nums_size + 1), --len;

    answer[last++] = nums[p.i][p.j];

    if (p.j == 0 && p.i + 1 < nums_size) {
      queue[tail] = (pos_t){ .i = p.i + 1, .j = 0 };
      tail = (tail + 1) % (nums_size + 1), ++len;
    }
    if (p.j + 1 < nums_col_size[p.i]) {
      queue[tail] = (pos_t){ .i = p.i, .j = p.j + 1 };
      tail = (tail + 1) % (nums_size + 1), ++len;
    }
  }

  return answer;
}