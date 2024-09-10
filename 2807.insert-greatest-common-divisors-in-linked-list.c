// @leet start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

static int
gcd(int a, int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

struct ListNode*
insertGreatestCommonDivisors(struct ListNode* head)
{
  struct ListNode* current = head;
  while (current->next) {
    struct ListNode* node = malloc(sizeof *node);
    *node =
      (struct ListNode){ .val = gcd(current->val, current->next->val), .next = current->next };
    current->next = node;
    current = node->next;
  }
  return head;
}
// @leet end