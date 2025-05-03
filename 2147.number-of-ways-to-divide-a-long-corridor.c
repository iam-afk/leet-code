int
numberOfWays(char* corridor)
{
  uint64_t const M = 1e9 + 7;

  int s = 0;
  char* t = corridor;
  uint64_t answer = 1;
  while (true) {
    while (s < 2 && *t != 0) {
      if (*t == 'S')
        ++s;
      ++t;
    }
    if (s < 2)
      return 0;
    if (*t == 0)
      return answer;
    int p = 0;
    while (*t != 0 && *t != 'S') {
      ++p;
      ++t;
    }
    if (*t == 0)
      return answer;
    answer = answer * (p + 1) % M;
    s = 0;
  }
  return answer;
}