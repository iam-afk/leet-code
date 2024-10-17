// @leet start
int
maximumSwap(int num)
{
  char buf[10];
  sprintf(buf, "%d", num);
  for (int i = 0; buf[i]; ++i) {
    int k = i;
    for (int j = i + 1; buf[j]; ++j)
      if (buf[j] > buf[k] || buf[j] == buf[k] && k != i)
        k = j;
    if (i != k) {
      char t = buf[i];
      buf[i] = buf[k];
      buf[k] = t;
      sscanf(buf, "%d", &num);
      return num;
    }
  }
  return num;
}
// @leet end