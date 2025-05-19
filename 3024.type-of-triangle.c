// @leet start
char*
triangleType(int* nums, int numsSize)
{
  int a = nums[0], b = nums[1], c = nums[2];
  if (a >= b + c || b >= a + c || c >= a + b)
    return "none";
  if (a == b && b == c)
    return "equilateral";
  if (a == b || a == c || b == c)
    return "isosceles";
  return "scalene";
}
// @leet end