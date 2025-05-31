#define min(a, b)                                                             \
  ({                                                                          \
    __typeof__(a) _a = (a);                                                   \
    __typeof__(b) _b = (b);                                                   \
    _a < _b ? _a : _b;                                                        \
  })

int
maximumElementAfterDecrementingAndRearranging(int* arr, int arr_size)
{
  int count[100001] = { 0 };
  for (int i = 0; i < arr_size; ++i)
    ++count[min(arr_size, arr[i])];
  int maximum = 1;
  for (int i = 2; i <= arr_size; ++i)
    maximum = min(i, maximum + count[i]);
  return maximum;
}