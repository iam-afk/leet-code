// @leet start
int
countStudents(int* students,
              int students_size,
              int* sandwiches,
              int sandwiches_size)
{
  int c = 0, s = 0;
  for (int i = 0; i < students_size; ++i)
    if (students[i] == 0)
      ++c;
    else
      ++s;
  for (int i = 0; i < sandwiches_size; ++i)
    if (sandwiches[i] == 0) {
      if (c == 0)
        return s;
      --c;
    } else {
      if (s == 0)
        return c;
      --s;
    }
  return 0;
}
// @leet end