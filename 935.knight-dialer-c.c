int
knightDialer(int n)
{
  int d[2][10] = { [0] = { [0 ... 9] = 1 } }, *p = d[0], *q = d[1];
  int const M = 1e9 + 7;
  for (int i = 1; i < n; ++i) {
    q[0] = (p[4] + p[6]) % M;
    q[1] = (p[6] + p[8]) % M;
    q[2] = (p[7] + p[9]) % M;
    q[3] = (p[4] + p[8]) % M;
    q[4] = ((p[3] + p[9]) % M + p[0]) % M;
    q[5] = 0;
    q[6] = ((p[1] + p[7]) % M + p[0]) % M;
    q[7] = (p[2] + p[6]) % M;
    q[8] = (p[1] + p[3]) % M;
    q[9] = (p[2] + p[4]) % M;
    int* t = p;
    p = q;
    q = t;
  }
  int answer = 0;
  for (int i = 0; i < 10; ++i) {
    answer = (answer + p[i]) % M;
  }
  return answer;
}