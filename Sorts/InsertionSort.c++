#include <bits/stdc++.h>

using namespace std;

void swap(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}

void insertionSort(vector<int> &arr)
{
  int n = arr.size();
  // iterate through every element

  for (int i = 1; i < n; i++)
  {
    int key = arr[i];
    int j = i - 1;

    // find the correct position for each element
    while (j >= 0 and arr[j] > key)
    {
      swap(arr[j + 1], arr[j]);
      j = j - 1;
    }

    // insert them in that position
    arr[j + 1] = key;
  }
}

void print(vector<int> arr)
{
  for (int i = 0; i < arr.size(); i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main()
{

  vector<int> arr = {300, -123, 1000, -23333, 0, 1, 2, 3, -4, -55, 6};
  int n = sizeof(arr) / sizeof(arr[0]);

  print(arr);

  insertionSort(arr);

  print(arr);
}