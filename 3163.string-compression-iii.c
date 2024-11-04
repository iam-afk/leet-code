// @leet start
char*
compressedString(char* word)
{
  char* ret = malloc(2 * strlen(word) + 1);
  int k = 0;
  for (int i = 0; word[i];) {
    int j = 1;
    while (j < 9 && word[i] == word[i + j])
      ++j;
    ret[k++] = '0' + j;
    ret[k++] = word[i];
    i += j;
  }
  ret[k] = 0;
  return ret;
}
// @leet end