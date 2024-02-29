// @leet start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool
isEvenOddTree(struct TreeNode* root)
{
  struct item
  {
    struct TreeNode* node;
    bool even;
  };
  struct item queue[UINT16_MAX + 1];
  uint16_t head = 0, tail = 0, len = 0;
  if (root != 0)
    queue[++len, tail++] = (struct item){ .node = root, .even = true };

  struct item prev = { .node = 0, .even = false };
  while (len > 0) {

    if (prev.even == queue[head].even)
      if (prev.even && prev.node->val >= queue[head].node->val ||
          !prev.even && prev.node->val <= queue[head].node->val)
        return false;

    prev = queue[--len, head++];

    if ((!prev.even || (prev.node->val & 1) == 0) && (prev.even || (prev.node->val & 1) == 1))
      return false;

    if (prev.node->left != 0)
      queue[++len, tail++] = (struct item){ .node = prev.node->left, .even = !prev.even };

    if (prev.node->right != 0)
      queue[++len, tail++] = (struct item){ .node = prev.node->right, .even = !prev.even };
  }

  return true;
}
// @leet end