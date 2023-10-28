#define M 1000000007

int
countVowelPermutation(int n)
{
  typedef struct
  {
    int a, e, i, o, u;
  } D;
  D d = { .a = 1, .e = 1, .i = 1, .o = 1, .u = 1 };
  for (int i = 1; i < n; ++i) {
    d = (D){ .a = d.e,
             .e = (d.a + d.i) % M,
             .i = ((d.a + d.e) % M + (d.o + d.u) % M) % M,
             .o = (d.i + d.u) % M,
             .u = d.a };
  }
  int r = d.a;
  r = (r + d.e) % M;
  r = (r + d.i) % M;
  r = (r + d.o) % M;
  r = (r + d.u) % M;
  return r;
}