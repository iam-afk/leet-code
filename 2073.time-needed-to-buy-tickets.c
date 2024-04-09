// @leet start
#define min(a, b)                                                                                  \
  ({                                                                                               \
    __typeof__(a) _a = (a);                                                                        \
    __typeof__(b) _b = (b);                                                                        \
    _a < _b ? _a : _b;                                                                             \
  })

int
timeRequiredToBuy(int* tickets, int tickets_size, int k)
{
  int a = 0;
  for (int i = 0; i < tickets_size; ++i) {
    a += min(tickets[i], tickets[k]);
    --tickets[i];
  }
  return a;
}
// @leet end