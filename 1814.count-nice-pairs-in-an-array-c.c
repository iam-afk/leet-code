static int
rev(int n)
{
  int r = 0;
  while (n > 0) {
    r = r * 10 + n % 10;
    n /= 10;
  }
  return r;
}

int
countNicePairs(int* nums, int nums_size)
{
  struct
  {
    int number, count;
    UT_hash_handle hh;
  } *hash = 0, *entry, entry_buffer[100000], *next_free_entry = entry_buffer;

  int const M = 1e9 + 7;
  int answer = 0;

  for (int i = 0; i < nums_size; ++i) {
    int d = nums[i] - rev(nums[i]);
    HASH_FIND_INT(hash, &d, entry);
    if (entry == 0) {
      entry = next_free_entry++;
      entry->number = d;
      entry->count = 0;
      HASH_ADD_INT(hash, number, entry);
    }
    answer = (answer + entry->count) % M;
    ++entry->count;
  }

  return answer;
}