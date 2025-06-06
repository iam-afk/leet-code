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
isSameTree(struct TreeNode* p, struct TreeNode* q)
{
  return (p == 0 && q == 0) ||
         (p != 0 && q != 0 && p->val == q->val &&
          isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
}
// @leet end