/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

static int
walk(struct TreeNode* node, int* sum, int* n)
{
  int answer = 0;
  if (node != NULL) {
    int subtree_sum = node->val, subtree_n = 1;
    answer += walk(node->left, &subtree_sum, &subtree_n);
    answer += walk(node->right, &subtree_sum, &subtree_n);
    if (node->val == subtree_sum / subtree_n)
      ++answer;
    *sum += subtree_sum;
    *n += subtree_n;
  }
  return answer;
}

int
averageOfSubtree(struct TreeNode* root)
{
  int sum = 0, n = 0;
  return walk(root, &sum, &n);
}