// @leet start
#define M ((int)1e9 + 7)

int
numTilings(int n)
{
  struct D
  {
    int none, up, down;
  } d[3] = { [0] = { .none = 1 } };

  for (int i = 0; i < n; ++i) {
    d[2].none = (d[2].none + d[0].none) % M;
    d[1].none = (d[1].none + d[0].none) % M;
    d[1].up = (d[1].up + d[0].none) % M;
    d[1].down = (d[1].down + d[0].none) % M;

    d[1].down = (d[1].down + d[0].up) % M;
    d[2].none = (d[2].none + d[0].up) % M;

    d[1].up = (d[1].up + d[0].down) % M;
    d[2].none = (d[2].none + d[0].down) % M;

    d[0] = d[1];
    d[1] = d[2];
    d[2] = (struct D){};
  }
  return d[0].none;
}
// @leet end