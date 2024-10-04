char
findTheDifference(char* s, char* t)
{
  int c[26] = {};
  while (*s != 0)
    c[*s++ - 'a']++;
  char a;
  while (*t != 0)
    if (--c[(a = *t++) - 'a'] < 0)
      break;
  return a;
}