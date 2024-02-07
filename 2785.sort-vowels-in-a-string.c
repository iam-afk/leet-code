char*
sortVowels(char* s)
{
  int vowels[128] = {
    ['A'] = 1, ['E'] = 2, ['I'] = 3, ['O'] = 4, ['U'] = 5,
    ['a'] = 6, ['e'] = 7, ['i'] = 8, ['o'] = 9, ['u'] = 10,
  };
  int count[11] = { 0 };
  for (char* t = s; *t != 0; ++t) {
    ++count[vowels[*t]];
  }
  char* t = s;
  for (int i = 1; *t != 0; ++t) {
    if (vowels[*t] == 0)
      continue;
    while (count[i] == 0)
      ++i;
    *t = " AEIOUaeiou"[i];
    --count[i];
  }
  return s;
}