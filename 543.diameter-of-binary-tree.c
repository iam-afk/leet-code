// @leet start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define max(a, b)                                                                                  \
  ({                                                                                               \
    __typeof__(a) _a = (a);                                                                        \
    __typeof__(b) _b = (b);                                                                        \
    _a > _b ? _a : _b;                                                                             \
  })

struct diameter_and_depth
{
  int diameter, depth;
};

static struct diameter_and_depth
diameter_and_depth(struct TreeNode* node)
{
  if (node == 0)
    return (struct diameter_and_depth){ .diameter = 0, .depth = 0 };
  struct diameter_and_depth left = diameter_and_depth(node->left);
  struct diameter_and_depth right = diameter_and_depth(node->right);
  return (struct diameter_and_depth){
    .diameter = max(left.depth + right.depth, max(left.diameter, right.diameter)),
    .depth = max(left.depth, right.depth) + 1,
  };
}

int
diameterOfBinaryTree(struct TreeNode* root)
{
  return diameter_and_depth(root).diameter;
}
// @leet end