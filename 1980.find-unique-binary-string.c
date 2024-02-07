char*
findDifferentBinaryString(char** nums, int nums_size)
{
  char* answer = malloc(nums_size + 1);
  for (int i = 0; i < nums_size; ++i) {
    answer[i] = '1' - nums[i][i] + '0';
  }
  answer[nums_size] = 0;
  return answer;
}