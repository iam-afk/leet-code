// @leet start
static int
compare_ints(void const* a, void const* b)
{
  return *(int const*)a - *(int const*)b;
}

long long
dividePlayers(int* skill, int skill_size)
{
  qsort(skill, skill_size, sizeof(int), compare_ints);
  int total = skill[0] + skill[skill_size - 1];
  long long chemistry = 0;
  for (int i = 0, j = skill_size - 1; i < j; ++i, --j) {
    if (skill[i] + skill[j] != total)
      return -1;
    chemistry += skill[i] * skill[j];
  }
  return chemistry;
}
// @leet end