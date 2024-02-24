// @leet start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <limits.h>
typedef struct
{
  int person;
  int time;
} node_t;

static int
compare_node_t(node_t const* a, node_t const* b)
{
  return a->time - b->time;
}

static int
compare_meetings(void const* a, void const* b)
{
  return (*(int* const*)a)[2] - (*(int* const*)b)[2];
}

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

HEAP_S(node_t, .time)

int*
findAllPeople(int n,
              int** meetings,
              int meetings_size,
              int* meetingsColSize,
              int first_person,
              int* return_size)
{
  int edge_count[100000] = { 0 };
  for (int i = 0; i < meetings_size; ++i) {
    ++edge_count[meetings[i][0]];
    ++edge_count[meetings[i][1]];
  }
  node_t* graph[100000];
  for (int i = 0; i < n; ++i)
    if (edge_count[i] > 0)
      graph[i] = calloc(edge_count[i], sizeof *graph[i]);

  int last[100000] = { 0 };
  qsort(meetings, meetings_size, sizeof(int*), compare_meetings);
  for (int i = 0; i < meetings_size; ++i) {
    graph[meetings[i][0]][last[meetings[i][0]]++] =
      (node_t){ .person = meetings[i][1], .time = meetings[i][2] };
    graph[meetings[i][1]][last[meetings[i][1]]++] =
      (node_t){ .person = meetings[i][0], .time = meetings[i][2] };
  }

  int shared_at[100000] = { [0] = -1, [1 ... 99999] = INT_MAX };
  node_t queue[200000];
  if (edge_count[0] > 0)
    memcpy(queue, graph[0], edge_count[0] * sizeof(node_t));
  int len = edge_count[0];
  queue[len] = (node_t){ .person = first_person, .time = 0 };
  sift_up_node_t(queue, len++);
  while (len > 0) {
    swap_node_t(queue, 0, --len);
    sift_down_node_t(queue, len, 0);
    node_t node = queue[len];

    if (shared_at[node.person] < node.time)
      continue;

    shared_at[node.person] = node.time;

    int left = -1, right = edge_count[node.person];
    while (left + 1 < right) {
      int m = left + (right - left) / 2;
      if (graph[node.person][m].time < node.time)
        left = m;
      else
        right = m;
    }
    for (int i = right; i < edge_count[node.person]; ++i) {
      int next = graph[node.person][i].person;
      if (shared_at[next] > graph[node.person][i].time) {
        queue[len] = graph[node.person][i];
        sift_up_node_t(queue, len++);
      }
    }
  }
  for (int i = 0; i < n; ++i)
    if (edge_count[i] > 0)
      free(graph[i]);

  *return_size = 0;
  for (int i = 0; i < n; ++i)
    if (shared_at[i] < INT_MAX)
      ++(*return_size);
  int* ret = calloc(*return_size, sizeof *ret);
  for (int i = 0, j = 0; i < n; ++i)
    if (shared_at[i] < INT_MAX)
      ret[j++] = i;
  return ret;
}
// @leet end