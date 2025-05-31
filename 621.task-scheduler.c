// @leet start
#define max(a, b)                                                             \
  ({                                                                          \
    __typeof__(a) _a = (a);                                                   \
    __typeof__(b) _b = (b);                                                   \
    _a > _b ? _a : _b;                                                        \
  })

int
leastInterval(char* tasks, int tasks_size, int n)
{
  int count[26] = { [0 ... 25] = 0 }, mx = 0;
  for (int i = 0; i < tasks_size; ++i)
    mx = max(mx, ++count[tasks[i] - 'A']);
  int ans = (mx - 1) * (n + 1);
  for (int i = 0; i < 26; ++i)
    if (count[i] == mx)
      ++ans;
  return max(ans, tasks_size);
}
// @leet end