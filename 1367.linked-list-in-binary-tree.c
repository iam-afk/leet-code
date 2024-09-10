// @leet start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
static bool
isSubPathFrom(struct TreeNode* node, struct ListNode* head)
{
  if (!head)
    return true;
  if (!node)
    return false;
  return node->val == head->val &&
         (isSubPathFrom(node->left, head->next) || isSubPathFrom(node->right, head->next));
}

bool
isSubPath(struct ListNode* head, struct TreeNode* root)
{
  if (!root)
    return false;
  if (isSubPathFrom(root, head))
    return true;
  return isSubPath(head, root->left) || isSubPath(head, root->right);
}
// @leet end