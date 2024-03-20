// @leet start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode*
mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2)
{
  struct ListNode head = { .next = list1 };
  struct ListNode* node_a = &head;
  for (int i = 0; i < a; ++i)
    node_a = node_a->next;
  struct ListNode* node_b = node_a->next;
  for (int i = a; i < b; ++i)
    node_b = node_b->next;
  node_a->next = list2;
  while (list2->next != 0)
    list2 = list2->next;
  list2->next = node_b->next;
  return head.next;
}
// @leet end