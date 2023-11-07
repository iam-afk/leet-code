static int
compare_ints(void const* a, void const* b)
{
  return *(int*)a - *(int*)b;
}

int
eliminateMaximum(int* dist, int dist_size, int* speed, int speed_size)
{
  for (int i = 0; i < dist_size; ++i)
    dist[i] = (dist[i] + speed[i] - 1) / speed[i];
  qsort(dist, dist_size, sizeof(int), compare_ints);
  int i = 0;
  while (i < dist_size && i < dist[i])
    ++i;
  return i;
}