#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}

void selectionSort(int arr[], int n)
{
  int minidx;

  for (int i = 0; i < n - 1; i++)
  {
    // assume least ele in starting positon
    minidx = i;

    for (int j = i + 1; j < n; j++)
    {
      // if min element found, update the minidx
      if (arr[j] < arr[minidx])
      {
        minidx = j;
      }
    }
    // if minidx refers to other than current least ele, then swap the values and increment in the loop
    if (i != minidx)
      swap(arr[i], arr[minidx]);
  }
}

void print(int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main()
{

  int arr[] = {300, -123, 1000, -23333, 0, 1, 2, 3, -4, -55, 6};
  int n = sizeof(arr) / sizeof(arr[0]);

  print(arr, n);

  selectionSort(arr, n);

  print(arr, n);
}