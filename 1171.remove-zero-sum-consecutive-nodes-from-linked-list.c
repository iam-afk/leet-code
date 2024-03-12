// @leet start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode*
removeZeroSumSublists(struct ListNode* head)
{
  struct ListNode *top = 0, *ptr = head;
  while (ptr != 0) {
    int sum = 0;
    struct ListNode* item = top;
    bool delete = false;
    while (item != 0) {
      sum += item->val;
      if (sum + ptr->val == 0) {
        delete = true;
        break;
      }
      item = item->next;
    }
    struct ListNode* current = ptr;
    ptr = ptr->next;
    if (delete)
      top = item->next;
    else if (current->val != 0) {
      current->next = top;
      top = current;
    }
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