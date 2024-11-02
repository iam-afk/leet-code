// @leet start
bool
isCircularSentence(char* sentence)
{
  char last = 0;
  for (int i = 0; sentence[i]; ++i) {
    if (sentence[i] == ' ' && sentence[i - 1] != sentence[i + 1])
      return false;
    last = sentence[i];
  }
  return *sentence == last;
}
// @leet end