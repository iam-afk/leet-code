static int
compare_ints(void const* a, void const* b)
{
  return *(int*)a - *(int*)b;
}

int
numBusesToDestination(int** routes, int routes_size, int* routes_col_size, int source, int target)
{
  if (source == target)
    return 0;
  bool used[500] = { false };
  typedef struct
  {
    int route, num;
  } queue_t;
  queue_t queue[500];
  int front = 0, tail = 0;
  for (int i = 0; i < routes_size; ++i) {
    qsort(routes[i], routes_col_size[i], sizeof(int), compare_ints);
    if (bsearch(&source, routes[i], routes_col_size[i], sizeof(int), compare_ints)) {
      queue[tail++] = (queue_t){ .route = i, .num = 1 };
      used[i] = true;
    }
  }
  while (front < tail) {
    queue_t item = queue[front++];
    if (bsearch(
          &target, routes[item.route], routes_col_size[item.route], sizeof(int), compare_ints)) {
      return item.num;
    }
    for (int i = 0; i < routes_col_size[item.route]; ++i) {
      for (int j = 0; j < routes_size; ++j) {
        if (used[j])
          continue;
        if (bsearch(
              &routes[item.route][i], routes[j], routes_col_size[j], sizeof(int), compare_ints)) {
          queue[tail++] = (queue_t){ .route = j, .num = item.num + 1 };
          used[j] = true;
        }
      }
    }
  }
  return -1;
}