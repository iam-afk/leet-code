// @leet start
#define max(a, b)                                                             \
  ({                                                                          \
    __typeof__(a) _a = (a);                                                   \
    __typeof__(b) _b = (b);                                                   \
    _a > _b ? _a : _b;                                                        \
  })

int
maxSubarrayLength(int* nums, int nums_size, int k)
{
  struct
  {
    int value, number;
    UT_hash_handle hh;
  } *hash = 0, *entry, *ptr, buffer[100000], *next = buffer;

  int answer = 0;

  int left = 0, right = 0;
  for (int left = 0, right = 0; right < nums_size; ++right) {
    HASH_FIND_INT(hash, &nums[right], entry);
    if (entry)
      ++entry->number;
    else {
      entry = next++;
      entry->value = nums[right];
      entry->number = 1;
      HASH_ADD_INT(hash, value, entry);
    }
    while (entry->number > k) {
      HASH_FIND_INT(hash, &nums[left], ptr);
      --ptr->number;
      ++left;
    }
    answer = max(answer, right - left + 1);
  }

  return answer;
}
// @leet end