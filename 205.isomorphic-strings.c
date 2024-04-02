// @leet start

bool
isIsomorphic(char* s, char* t)
{
  int map[256] = { [0 ... 255] = 0 };
  bool used[256] = { [0 ... 255] = false };
  for (; *s != 0 && *t != 0; ++s, ++t) {
    if (map[*s] > 0) {
      if (map[*s] != *t)
        return false;
    } else if (used[*t])
      return false;
    map[*s] = *t;
    used[*t] = true;
  }
  return *s == 0 && *t == 0;
}
// @leet end