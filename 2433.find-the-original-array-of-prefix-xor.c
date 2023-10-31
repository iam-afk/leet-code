/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int*
findArray(int* pref, int prefSize, int* returnSize)
{
  int x = 0;
  for (int i = 0; i < prefSize; ++i) {
    pref[i] ^= x;
    x ^= pref[i];
  }
  *returnSize = prefSize;
  return pref;
}