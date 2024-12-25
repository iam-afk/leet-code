// @leet start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void
largestValuesAt(struct TreeNode* node, int row, int* largest, int* rows)
{
  if (node) {
    if (*rows == row) {
      largest[row] = node->val;
      ++*rows;
    } else if (node->val > largest[row]) {
      largest[row] = node->val;
    }
    largestValuesAt(node->left, row + 1, largest, rows);
    largestValuesAt(node->right, row + 1, largest, rows);
  }
}

int*
largestValues(struct TreeNode* root, int* retSize)
{
  int largest[10000];
  *retSize = 0;
  largestValuesAt(root, 0, largest, retSize);
  int* ret = calloc(*retSize, sizeof *ret);
  memcpy(ret, largest, *retSize * sizeof *ret);
  return ret;
}
// @leet end