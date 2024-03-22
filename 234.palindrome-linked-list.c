// @leet start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool
isPalindrome(struct ListNode* head)
{
  struct ListNode *fast = head, *slow = head, *first = NULL, *second;
  while (fast != 0 && fast->next != 0) {
    fast = fast->next->next;

    struct ListNode* slow_next = slow->next;
    slow->next = first;
    first = slow;
    slow = slow_next;
  }

  second = slow;
  if (fast != 0)
    second = second->next;

  while (first != 0 && second != 0 && first->val == second->val) {
    first = first->next;
    second = second->next;
  }

  return first == 0 && second == 0;
}
// @leet end