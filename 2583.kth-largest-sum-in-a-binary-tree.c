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
updateLevelSum(struct TreeNode* node,
               int level,
               long long* sums,
               int* sumsSize)
{
  if (node) {
    if (level == *sumsSize)
      sums[(*sumsSize)++] = 0;
    sums[level] += node->val;
    updateLevelSum(node->left, level + 1, sums, sumsSize);
    updateLevelSum(node->right, level + 1, sums, sumsSize);
  }
}

static int
compare_longs(void const* a, void const* b)
{
  long long x = *(long long const*)a;
  long long y = *(long long const*)b;
  if (x > y)
    return -1;
  if (x < y)
    return 1;
  return 0;
}

long long
kthLargestLevelSum(struct TreeNode* root, int k)
{
  long long* sums = calloc(N, sizeof *sums);

  int sumsSize = 0;
  updateLevelSum(root, 0, sums, &sumsSize);

  if (k > sumsSize)
    return -1;

  qsort(sums, sumsSize, sizeof(long long), compare_longs);

  long long kth = sums[k - 1];

  free(sums);

  return kth > 0 ? kth : -1;
}
// @leet end