// @leet start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode*
removeNodes(struct ListNode* head)
{
  struct ListNode* top = 0;
  while (head != 0) {
    while (top != 0 && head->val > top->val)
      top = top->next;
    struct ListNode* cur = head;
    head = head->next;
    cur->next = top;
    top = cur;
  }
  head = 0;
  while (top != 0) {
    struct ListNode* cur = top;
    top = top->next;
    cur->next = head;
    head = cur;
  }
  return head;
}
// @leet end