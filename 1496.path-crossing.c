// @leet start
bool
isPathCrossing(char* path)
{
  struct
  {
    int x;
    UT_hash_handle hh;
  } *set, *pos, buffer[10000], *next = buffer;
  int x = 0;
  pos = next++;
  pos->x = x;
  HASH_ADD_INT(set, x, pos);
  while (*path) {
    switch (*path++) {
      case 'N':
        x -= 1 << 16;
        break;
      case 'S':
        x += 1 << 16;
        break;
      case 'E':
        x += 1;
        break;
      case 'W':
        x -= 1;
        break;
    }
    HASH_FIND_INT(set, &x, pos);
    if (pos)
      return true;
    pos = next++;
    pos->x = x;
    HASH_ADD_INT(set, x, pos);
  }
  return false;
}
// @leet end