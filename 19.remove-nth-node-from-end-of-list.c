// @leet start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode*
removeNthFromEnd(struct ListNode* head, int n)
{
  struct ListNode *ahead = head, *node = head;
  for (int i = 0; i < n; ++i)
    ahead = ahead->next;
  if (ahead == 0) {
    struct ListNode* remove = head;
    head = head->next;
    free(remove);
    return head;
  }
  while (ahead->next != 0) {
    node = node->next;
    ahead = ahead->next;
  }
  struct ListNode* remove = node->next;
  node->next = node->next->next;
  free(remove);
  return head;
}
// @leet end