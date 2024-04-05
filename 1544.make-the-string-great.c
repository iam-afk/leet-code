// @leet start
char*
makeGood(char* s)
{
  char* t = malloc(101);
  int i = 0;
  for (; *s != 0; ++s)
    if (i > 0 && (*s ^ t[i - 1]) == 0x20)
      --i;
    else
      t[i++] = *s;
  t[i] = 0;
  return t;
}
// @leet end