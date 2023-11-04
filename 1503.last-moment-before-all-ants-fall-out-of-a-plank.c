#define max(a, b)                                                                                  \
  ({                                                                                               \
    __typeof__(a) _a = (a);                                                                        \
    __typeof__(b) _b = (b);                                                                        \
    _a > _b ? _a : _b;                                                                             \
  })

int
getLastMoment(int n, int* left, int left_size, int* right, int right_size)
{
  int a = 0;
  for (int i = 0; i < left_size; ++i)
    a = max(a, left[i]);
  for (int i = 0; i < right_size; ++i)
    a = max(a, n - right[i]);
  return a;
}