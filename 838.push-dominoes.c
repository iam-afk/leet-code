// @leet start
char*
pushDominoes(char* dominoes)
{
  int d[100000] = {};
  int i = 0;
  for (int r = -1; dominoes[i]; ++i)
    if (dominoes[i] == '.' && r >= 0)
      d[i] += ++r;
    else if (dominoes[i] == 'R')
      r = 0;
    else
      r = -1;
  for (int l = -1; i-- > 0;) {
    if (dominoes[i] == '.' && l >= 0)
      ++l;
    else if (dominoes[i] == 'L')
      l = 0;
    else
      l = -1;
    if (dominoes[i] == '.')
      dominoes[i] = l == d[i] || l < 0 && d[i] == 0   ? '.'
                    : l <= d[i] && l > 0 || d[i] == 0 ? 'L'
                                                      : 'R';
  }

  return dominoes;
}
// @leet end