// @leet start
#include <limits.h>
#define HEAP_S(type, field)                                                                        \
  static void swap_##type(type* a, int i, int j)                                                   \
  {                                                                                                \
    type t = a[i];                                                                                 \
    a[i] = a[j];                                                                                   \
    a[j] = t;                                                                                      \
  }                                                                                                \
  static void sift_up_##type(type* a, int i)                                                       \
  {                                                                                                \
    while (a[i] field < a[(i - 1) / 2] field) {                                                    \
      swap_##type(a, i, (i - 1) / 2);                                                              \
      i = (i - 1) / 2;                                                                             \
    }                                                                                              \
  }                                                                                                \
  static void sift_down_##type(type* a, int n, int i)                                              \
  {                                                                                                \
    while (2 * i + 1 < n) {                                                                        \
      int l = 2 * i + 1, r = 2 * i + 2;                                                            \
      int j = l;                                                                                   \
      if (r < n && a[r] field < a[l] field)                                                        \
        j = r;                                                                                     \
      if (a[i] field < a[j] field)                                                                 \
        break;                                                                                     \
      swap_##type(a, i, j);                                                                        \
      i = j;                                                                                       \
    }                                                                                              \
  }
#define HEAP(type) HEAP_S(type, )

typedef struct
{
  int city, price, stops;
} node_t;

HEAP_S(node_t, .price)

int
findCheapestPrice(int n,
                  int** flights,
                  int flightsSize,
                  int* flightsColSize,
                  int src,
                  int dst,
                  int k)
{
  int graph[100][100] = { [0 ... 99] = { 0 } };
  for (int i = 0; i < flightsSize; ++i)
    graph[flights[i][0]][flights[i][1]] = flights[i][2];
  int visited[100] = { [0 ... 99] = INT_MAX };

  node_t queue[10000];
  int qlen = 0;
  queue[qlen++] = (node_t){ .stops = -1, .city = src, .price = 0 };
  while (qlen > 0) {
    swap_node_t(queue, 0, --qlen);
    sift_down_node_t(queue, qlen, 0);
    if (queue[qlen].city == dst)
      return queue[qlen].price;
    int v = queue[qlen].city, price = queue[qlen].price, stops = queue[qlen].stops;
    if (stops == k)
      continue;
    visited[v] = stops;
    for (int j = 0; j < n; ++j)
      if (graph[v][j] > 0 && stops + 1 < visited[j]) {
        queue[qlen] = (node_t){ .city = j, .price = price + graph[v][j], .stops = stops + 1 };
        sift_up_node_t(queue, qlen++);
      }
  }
  return -1;
}
// @leet end