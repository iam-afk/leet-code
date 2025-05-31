
static int
compare_ints(void const* a, void const* b)
{
  return *(int*)a - *(int*)b;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int*
fairCandySwap(int* alice_sizes,
              int alice_sizes_size,
              int* bob_sizes,
              int bob_sizes_size,
              int* size)
{
  int* answer = calloc(2, sizeof *answer);
  int d = 0;
  for (int i = 0; i < alice_sizes_size; ++i)
    d += alice_sizes[i];
  for (int i = 0; i < bob_sizes_size; ++i)
    d -= bob_sizes[i];
  qsort(bob_sizes, bob_sizes_size, sizeof(int), compare_ints);
  for (int i = 0; i < alice_sizes_size; ++i) {
    int alice_size = alice_sizes[i], bob_size = alice_size - d / 2;
    if (bsearch(
          &bob_size, bob_sizes, bob_sizes_size, sizeof(int), compare_ints)) {
      answer[0] = alice_size;
      answer[1] = bob_size;
      break;
    }
  }
  *size = 2;
  return answer;
}