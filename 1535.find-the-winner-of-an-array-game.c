int
getWinner(int* arr, int arr_size, int k)
{
  int winner = arr[0];
  for (int i = 1, streak = 0; i < arr_size && streak < k; ++i) {
    if (winner > arr[i])
      streak++;
    else {
      winner = arr[i];
      streak = 1;
    }
  }
  return winner;
}