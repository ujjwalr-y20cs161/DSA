#include <bits/stdc++.h>

using namespace std;

// swapping without using the temporary variable
void swap(int &a, int &b)
{
  a = a + b;
  b = a - b;
  a = a - b;
}

void BubbleSortOpt(int arr[], int n)
{

  for (int i = 0; i < n - 1; i++)
  {
    // swap variable
    bool swapped = false;

    for (int j = 0; j < n - i - 1; j++)
    {
      // if at least one iteration goes without swapping any elements : it suggests the array is already
      // in the sorted order hence we break out of the loop.
      if (arr[j] > arr[j + 1])
      {
        swap(arr[j], arr[j + 1]);
        swapped = true;
      }
    }

    if (!swapped)
      break;
  }
}

int main()
{

  int arr[] = {10, 1, 12, 30, -1204, -320, 48000, 1, 133};
  int n = sizeof(arr) / sizeof(arr[0]);

  for (auto i : arr)
  {
    cout << i << " ";
  }
  cout << endl;

  BubbleSortOpt(arr, n);

  for (auto i : arr)
  {
    cout << i << " ";
  }
  cout << endl;
}