// @leet start
#define min(a, b)                                                                                  \
  ({                                                                                               \
    __typeof__(a) _a = (a);                                                                        \
    __typeof__(b) _b = (b);                                                                        \
    _a < _b ? _a : _b;                                                                             \
  })

#define max(a, b)                                                                                  \
  ({                                                                                               \
    __typeof__(a) _a = (a);                                                                        \
    __typeof__(b) _b = (b);                                                                        \
    _a > _b ? _a : _b;                                                                             \
  })

int
closestMeetingNode(int* edges, int edgesSize, int node1, int node2)
{
  int d1[100000], d2[100000];
  for (int v = 0; v < edgesSize; ++v)
    d1[v] = d2[v] = -1;
  for (int v = node1, i = 0; v != -1 && d1[v] < 0; v = edges[v], ++i)
    d1[v] = i;
  int ans = -1, mn = INT_MAX;

  for (int v = node2, i = 0; v != -1 && d2[v] < 0; v = edges[v], ++i) {
    d2[v] = i;
    if (d1[v] < 0)
      continue;
    int mx = max(i, d1[v]);
    if (mx < mn) {
      ans = v;
      mn = mx;
    } else if (mx == mn && v < ans)
      ans = v;
  }
  return ans < INT_MAX ? ans : -1;
}
// @leet end