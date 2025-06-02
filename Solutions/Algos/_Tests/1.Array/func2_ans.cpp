int func2(int arr[], int N)
{
  int a[101] = {
      0,
  };

  for (int i = 0; i < N; i++)
  {
    if (a[100 - arr[i]] == 1)
      return 1;

    a[arr[i]] = 1;
  }
  return 0;
}
