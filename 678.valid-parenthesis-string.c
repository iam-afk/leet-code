// @leet start
bool
checkValidString(char* s)
{
  int n = strlen(s);
  int a = 0, b = 0;
  for (int i = 0; s[i] != 0; ++i) {
    if (s[i] == '(' || s[i] == '*')
      ++a;
    else
      --a;
    if (s[n - i - 1] == ')' || s[n - i - 1] == '*')
      ++b;
    else
      --b;
    if (a < 0 || b < 0)
      return false;
  }
  return true;
}
// @leet end