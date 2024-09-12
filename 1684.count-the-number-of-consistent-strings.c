// @leet start

int
countConsistentStrings(char* allowed, char** words, int wordsSize)
{
  bool set[26] = { [0 ... 25] = false };
  while (*allowed)
    set[*allowed++ - 'a'] = true;
  int answewr = 0;
  for (int i = 0; i < wordsSize; ++i) {
    bool consistent = true;
    char* word = words[i];
    while (consistent && *word)
      consistent = set[*word++ - 'a'];
    answewr += consistent;
  }
  return answewr;
}
// @leet end