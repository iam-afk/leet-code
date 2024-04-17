// @leet start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define N ((size_t)8500)

static char ret[N + 1];

static void
smallest_from_leaf(struct TreeNode* node, char* buf)
{
  *--buf = node->val + 'a';
  bool is_leaf = true;
  if (node->left) {
    smallest_from_leaf(node->left, buf);
    is_leaf = false;
  }
  if (node->right) {
    smallest_from_leaf(node->right, buf);
    is_leaf = false;
  }
  if (is_leaf)
    if (*ret == 0 || strcmp(buf, ret) < 0)
      strcpy(ret, buf);
}

char*
smallestFromLeaf(struct TreeNode* root)
{
  *ret = 0;
  char buf[N + 1] = { [N] = 0 };
  smallest_from_leaf(root, buf + N);
  return ret;
}
// @leet end