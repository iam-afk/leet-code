// @leet start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int**
mergeArrays(int** nums1,
            int nums1Size,
            int* nums1ColSize,
            int** nums2,
            int nums2Size,
            int* nums2ColSize,
            int* returnSize,
            int** returnColumnSizes)
{
  *returnSize = 0;
  int** ret = calloc(400, sizeof *ret);
  int i = 0, j = 0;
  while (i < nums1Size && j < nums2Size) {
    int* row = calloc(2, sizeof *row);
    if (nums1[i][0] == nums2[j][0])
      row[0] = nums1[i][0], row[1] = nums1[i++][1] + nums2[j++][1];
    else if (nums1[i][0] < nums2[j][0])
      row[0] = nums1[i][0], row[1] = nums1[i++][1];
    else
      row[0] = nums2[j][0], row[1] = nums2[j++][1];
    ret[(*returnSize)++] = row;
  }
  while (i < nums1Size) {
    int* row = calloc(2, sizeof *row);
    row[0] = nums1[i][0], row[1] = nums1[i++][1];
    ret[(*returnSize)++] = row;
  }
  while (j < nums2Size) {
    int* row = calloc(2, sizeof *row);
    row[0] = nums2[j][0], row[1] = nums2[j++][1];
    ret[(*returnSize)++] = row;
  }
  *returnColumnSizes = calloc(*returnSize, sizeof **returnColumnSizes);
  for (int i = 0; i < *returnSize; ++i)
    (*returnColumnSizes)[i] = 2;
  return ret;
}
// @leet end