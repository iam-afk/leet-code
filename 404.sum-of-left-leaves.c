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
update(struct TreeNode* node, bool left, int* sum)
{
  if (node == 0)
    return;
  if (node->left == 0 && node->right == 0 && left)
    *sum += node->val;
  update(node->left, true, sum);
  update(node->right, false, sum);
}

int
sumOfLeftLeaves(struct TreeNode* root)
{
  int sum = 0;
  update(root, false, &sum);
  return sum;
}
// @leet end