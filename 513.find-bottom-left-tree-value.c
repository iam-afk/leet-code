// @leet start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct leftmost_at
{
  int val;
  int depth;
};

static void
update_leftmost_at_depth(struct TreeNode* node,
                         struct leftmost_at* leftmost_at,
                         int depth)
{
  if (node == 0)
    return;
  if (depth > leftmost_at->depth)
    *leftmost_at = (struct leftmost_at){ .val = node->val, .depth = depth };
  update_leftmost_at_depth(node->left, leftmost_at, depth + 1);
  update_leftmost_at_depth(node->right, leftmost_at, depth + 1);
}

int
findBottomLeftValue(struct TreeNode* root)
{
  struct leftmost_at leftmost_at = {};
  update_leftmost_at_depth(root, &leftmost_at, 1);
  return leftmost_at.val;
}
// @leet end