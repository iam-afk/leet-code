// @leet start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int**
spiralMatrix(int m, int n, struct ListNode* head, int* returnSize, int** returnColumnSizes)
{
  int** ret = calloc(m, sizeof *ret);
  *returnSize = m;
  *returnColumnSizes = calloc(m, sizeof *returnColumnSizes);
  for (int i = 0; i < m; ++i) {
    ret[i] = calloc(n, sizeof **ret);
    memset(ret[i], -1, n * sizeof **ret);
    (*returnColumnSizes)[i] = n;
  }

  int i = 0, j = -1, di = 0, dj = 1;
  while (head) {
    if (0 <= i + di && i + di < m && 0 <= j + dj && j + dj < n && ret[i + di][j + dj] == -1) {
      ret[i += di][j += dj] = head->val;
      head = head->next;
    } else {
      int t = di;
      di = dj;
      dj = -t;
    }
  }

  return ret;
}
// @leet end