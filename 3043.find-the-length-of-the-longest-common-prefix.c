// @leet start
int
longestCommonPrefix(int* arr1, int arr1Size, int* arr2, int arr2Size)
{
  struct
  {
    int num, len;
    UT_hash_handle hh;
  } *head = 0, buffer[9 * (size_t)5e4], *ptr, *next = buffer;

  for (int i = 0; i < arr1Size; ++i) {
    for (int n = arr1[i]; n > 0; n /= 10) {
      HASH_FIND_INT(head, &n, ptr);
      if (ptr)
        break;
      ptr = next++;
      ptr->num = n;
      HASH_ADD_INT(head, num, ptr);
    }
  }

  int mx = 0;
  for (int i = 0; i < arr2Size; ++i) {
    int n = arr2[i];
    for (int n = arr2[i]; n > 0; n /= 10) {
      HASH_FIND_INT(head, &n, ptr);
      if (ptr) {
        int l = 0, p = 1;
        while (p <= n)
          p *= 10, ++l;
        if (mx < l)
          mx = l;
      }
    }
  }

  return mx;
}
// @leet end