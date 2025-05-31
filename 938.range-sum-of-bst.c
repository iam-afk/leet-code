// @leet start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int
rangeSumBST(struct TreeNode* root, int low, int high)
{
  if (root == 0)
    return 0;
  if (root->val > high)
    return rangeSumBST(root->left, low, high);
  if (root->val < low)
    return rangeSumBST(root->right, low, high);
  return rangeSumBST(root->left, low, high) + root->val +
         rangeSumBST(root->right, low, high);
}
// @leet end