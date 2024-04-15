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
sum_root_to_leaf_path(struct TreeNode* node, int n, int* sum)
{
  if (node == 0)
    return;
  int x = n * 10 + node->val;
  if (node->left == 0 && node->right == 0)
    *sum += x;
  else {
    sum_root_to_leaf_path(node->left, x, sum);
    sum_root_to_leaf_path(node->right, x, sum);
  }
}

int
sumNumbers(struct TreeNode* root)
{
  int sum = 0;
  sum_root_to_leaf_path(root, 0, &sum);
  return sum;
}
// @leet end