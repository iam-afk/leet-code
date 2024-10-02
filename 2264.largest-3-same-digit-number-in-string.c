char*
largestGoodInteger(char* num)
{
  char* max = "";
  for (int i = 2; num[i] != 0; ++i)
    if (num[i] > max[0] && num[i] == num[i - 1] && num[i - 1] == num[i - 2])
      max = num + i - 2;
  if (max[0] != 0)
    max[3] = 0;
  return max;
}