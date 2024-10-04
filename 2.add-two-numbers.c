/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode*
addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
  struct ListNode number, *tail = &number;
  int sum = 0;
  while (l1 != 0 || l2 != 0 || sum != 0) {
    if (l1 != 0) {
      sum += l1->val;
      l1 = l1->next;
    }
    if (l2 != 0) {
      sum += l2->val;
      l2 = l2->next;
    }
    tail->next = malloc(sizeof(struct ListNode));
    tail = tail->next;
    *tail = (struct ListNode){ .val = sum % 10, .next = 0 };
    sum /= 10;
  }
  return number.next;
}