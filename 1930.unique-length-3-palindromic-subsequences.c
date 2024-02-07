int
countPalindromicSubsequence(char* s)
{
  size_t n = strlen(s);

  int set[100000];

  int prefix_set = 0;
  for (int i = 0; i < n; ++i) {
    set[i] = prefix_set;
    prefix_set |= 1 << (s[i] - 'a');
  }
  int suffix_set = 0;
  for (int j = n; j-- > 0;) {
    set[j] &= suffix_set;
    suffix_set |= 1 << (s[j] - 'a');
  }

  int letter_set[26] = { 0 };
  for (int i = 1; i < n - 1; ++i) {
    letter_set[s[i] - 'a'] |= set[i];
  }

  int answer = 0;
  for (int i = 0; i < 26; ++i) {
    answer += __builtin_popcount(letter_set[i]);
  }

  return answer;
}