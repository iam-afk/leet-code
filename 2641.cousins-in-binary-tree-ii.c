// @leet start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define N (size_t)1e5

static void
updateDepthSums(struct TreeNode* node, int depth, int* sums, int* sumsSize)
{
  if (node) {
    if (depth == *sumsSize)
      sums[(*sumsSize)++] = 0;
    sums[depth] += node->val;
    updateDepthSums(node->left, depth + 1, sums, sumsSize);
    updateDepthSums(node->right, depth + 1, sums, sumsSize);
  }
}

static void
replaceCousins(struct TreeNode* node, int depth, int cousinsSum, int* sums)
{
  if (!node)
    return;
  node->val = sums[depth] - cousinsSum;
  cousinsSum = 0;
  if (node->left)
    cousinsSum += node->left->val;
  if (node->right)
    cousinsSum += node->right->val;
  replaceCousins(node->left, depth + 1, cousinsSum, sums);
  replaceCousins(node->right, depth + 1, cousinsSum, sums);
}

struct TreeNode*
replaceValueInTree(struct TreeNode* root)
{
  int* sums = calloc(N, sizeof *sums);

  int maxDepth = 0;
  updateDepthSums(root, 0, sums, &maxDepth);

  replaceCousins(root, 0, root->val, sums);

  free(sums);

  return root;
}
// @leet end