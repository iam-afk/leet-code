// @leet start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode*
modifiedList(int* nums, int numsSize, struct ListNode* head)
{
  bool set[100001] = {};
  for (int i = 0; i < numsSize; ++i)
    set[nums[i]] = true;
  struct ListNode d = { .next = head }, *p = &d;
  while (p->next)
    if (set[p->next->val])
      p->next = p->next->next;
    else
      p = p->next;
  return d.next;
}
// @leet end