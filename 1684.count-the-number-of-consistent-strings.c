// @leet start

int
countConsistentStrings(char* allowed, char** words, int wordsSize)
{
  unsigned set = 0;
  while (*allowed)
    set |= 1 << (*allowed++ - 'a');
  int answewr = 0;
  for (int i = 0; i < wordsSize; ++i) {
    bool consistent = true;
    char* word = words[i];
    while (consistent && *word)
      consistent = (set & 1 << (*word++ - 'a')) != 0;
    answewr += consistent;
  }
  return answewr;
}
// @leet end