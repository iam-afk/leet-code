// @leet start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

static void
do_in_order(struct TreeNode* node, int* arr, int* index)
{
  if (node == 0)
    return;
  do_in_order(node->left, arr, index);
  arr[(*index)++] = node->val;
  do_in_order(node->right, arr, index);
}

static struct TreeNode*
construct(int* arr, int left, int right)
{
  if (left >= right)
    return 0;
  int middle = (left + right) / 2;
  struct TreeNode* node = malloc(sizeof(struct TreeNode));
  node->left = construct(arr, left, middle);
  node->val = arr[middle];
  node->right = construct(arr, middle + 1, right);
  return node;
}

struct TreeNode*
balanceBST(struct TreeNode* root)
{
  static int in_order[(size_t)1e4];
  int n = 0;
  do_in_order(root, in_order, &n);
  return construct(in_order, 0, n);
}
// @leet end