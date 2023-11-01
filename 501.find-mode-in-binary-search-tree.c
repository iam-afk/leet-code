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

static void
walk(struct TreeNode* node, int* stack, int* count, int* size)
{
  if (node == NULL)
    return;
  walk(node->left, stack, count, size);
  if (*size == 0 || stack[*size - 1] != node->val) {
    stack[*size] = node->val;
    count[*size] = 1;
    ++*size;
  } else {
    int index = *size - 1;
    while (index > 0 && count[index - 1] == count[*size - 1])
      --index;
    stack[index] = stack[*size - 1];
    count[index] = count[*size - 1] + 1;
    *size = index + 1;
  }
  walk(node->right, stack, count, size);
}

#define N 10000

int*
findMode(struct TreeNode* root, int* size)
{
  *size = 0;
  int* modes = calloc(N, sizeof *modes);

  int count[N];

  walk(root, modes, count, size);
  while (*size > 0 && count[0] > count[*size - 1])
    --*size;
  return modes;
}
