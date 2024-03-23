// @leet start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void
reorderList(struct ListNode* head)
{
  struct ListNode *slow = head, *fast = head;
  while (fast != 0 && fast->next != 0) {
    slow = slow->next;
    fast = fast->next->next;
  }
  struct ListNode *tail = 0, *node = slow->next;
  slow->next = 0;
  while (node != 0) {
    struct ListNode* next = node->next;
    node->next = tail;
    tail = node;
    node = next;
  }
  struct ListNode dump = { .next = 0 }, *last = &dump;

  while (tail != 0) {
    last->next = head;
    head = head->next;
    last = last->next;
    last->next = tail;
    tail = tail->next;
    last = last->next;
  }
  last->next = head;
  head = dump.next;
}
// @leet end