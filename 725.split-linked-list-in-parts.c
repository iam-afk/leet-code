// @leet start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct ListNode**
splitListToParts(struct ListNode* head, int k, int* returnSize)
{
  struct ListNode** ret = calloc(k, sizeof(struct ListNode*));
  *returnSize = k;

  for (int i = 0; i < k; ++i) {
    struct ListNode *slow = head, *fast = head;
    while (fast) {
      for (int j = i; fast && j < k; ++j)
        fast = fast->next;
      struct ListNode* last = slow;
      slow = slow->next;
      if (!fast)
        last->next = 0;
    }
    ret[i] = head;
    head = slow;
  }

  return ret;
}
// @leet end