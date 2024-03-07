// @leet start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode*
middleNode(struct ListNode* head)
{
  struct ListNode *slow = head, *fast = head;
  while (fast != 0 && fast->next != 0) {
    fast = fast->next->next;
    slow = slow->next;
  }
  return slow;
}
// @leet end