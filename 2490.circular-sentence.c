// @leet start
bool
isCircularSentence(char* sentence)
{
  char last = 0;
  int i = 0;
  while (sentence[i]) {
    while (sentence[i] && sentence[i] != ' ')
      last = sentence[i++];
    if (sentence[i] == 0)
      break;
    while (sentence[i] == ' ')
      ++i;
    if (sentence[i] && sentence[i] != last)
      return false;
  }
  return *sentence == last;
}
// @leet end