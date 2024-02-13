// @leet start
char*
firstPalindrome(char** words, int words_size)
{
  for (int i = 0; i < words_size; ++i) {
    int l = 0, r = strlen(words[i]) - 1;
    while (l < r && words[i][l] == words[i][r])
      ++l, --r;
    if (l >= r)
      return words[i];
  }
  return "";
}
// @leet end