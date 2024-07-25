// @leet start
class Solution {
    public int[] sortArray(int[] nums) {
        sortArray(nums, new int[nums.length], 0, nums.length);
        return nums;
    }

    private void sortArray(int[] nums, int[] sorted, int left, int right) {
        if (left + 1 >= right)
            return;
        int mid = left + (right - left) / 2;
        sortArray(nums, sorted, left, mid);
        sortArray(nums, sorted, mid, right);
        int i = left, j = mid, k = left;
        while (i < mid && j < right)
            if (nums[i] < nums[j])
                sorted[k++] = nums[i++];
            else
                sorted[k++] = nums[j++];
        while (i < mid) 
            sorted[k++] = nums[i++];
        while (j < right)
            sorted[k++] = nums[j++];
        System.arraycopy(sorted, left, nums, left, right - left);
    }
}
// @leet end