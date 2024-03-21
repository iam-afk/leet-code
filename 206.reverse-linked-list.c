// @leet start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode*
reverseList(struct ListNode* head)
{
  struct ListNode* ret = 0;
  while (head != 0) {
    struct ListNode* node = head->next;
    head->next = ret;
    ret = head;
    head = node;
  }
  return ret;
}
// @leet end