int
garbageCollection(char** garbage,
                  int garbage_size,
                  int* travel,
                  int travel_size)
{
  int prefix[100000];
  prefix[0] = 0;
  for (int i = 1; i <= travel_size; ++i)
    prefix[i] = prefix[i - 1] + travel[i - 1];
  int count[4] = { 0 }, last_index[4] = { 0 };
  for (int i = 0; i < garbage_size; ++i) {
    for (char* s = garbage[i]; *s != 0; ++s) {
      ++count[(*s - 'A') & 3];
      last_index[(*s - 'A') & 3] = i;
    }
  }
  int answer = 0;
  for (char* s = "MPG"; *s != 0; ++s)
    answer += count[(*s - 'A') & 3] + prefix[last_index[(*s - 'A') & 3]];
  return answer;
}