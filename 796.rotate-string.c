// @leet start
bool
rotateString(char* s, char* goal)
{
  int n = strlen(s), m = strlen(goal);
  if (n != m)
    return false;
  char buf[201];
  strcat(buf, s);
  strcat(buf + n, s);
  return strstr(buf, goal);
}
// @leet end