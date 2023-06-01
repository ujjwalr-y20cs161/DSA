#include <bits/stdc++.h>
#include <iostream>
#define endd "\n"
using namespace std;

void swap(int &p, int &q)
{
  int temp = p;
  p = q;
  q = temp;
}

void printArr(int arr[], int n)
{
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << "\n";
}

void printVec(vector<int> vec)
{
  for (auto i : vec)
    cout << i << " ";
  cout << endd;
}

void Heapify(int arr[], int n, int i)
{
  int large = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n and arr[left] > arr[large])
  {
    large = left;
  }
  if (right < n and arr[right] > arr[large])
  {
    large = right;
  }

  if (large != i)
  {
    swap(arr[i], arr[large]);
    Heapify(arr, n, large);
  }
}

void HeapSort(int arr[], int n)
{
  for (int i = n / 2 - 1; i >= 0; i--)
  {
    Heapify(arr, n, i);
  }

  for (int i = n - 1; i >= 0; i--)
  {
    swap(arr[0], arr[i]);
    Heapify(arr, i, 0);
  }
}

int parition(int arr[], int low, int high)
{
  int pivot = arr[low];
  int i = low, j = high;

  while (i < j)
  {
    while (i < high and arr[i] <= pivot)
    {
      i++;
    }
    while (j >= low and arr[j] > pivot)
    {
      j--;
    }

    if (i < j)
    {
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[j], arr[low]);
  return j;
}

void QuickSort(int arr[], int low, int high)
{
  if (low < high)
  {
    int p = parition(arr, low, high);
    QuickSort(arr, low, p - 1);
    QuickSort(arr, p + 1, high);
  }
}

void Merge(int arr[], int low, int mid, int high)
{
  vector<int> temp;
  int i = low, j = mid + 1;
  while (i <= mid and j <= high)
  {
    if (arr[i] <= arr[j])
    {
      temp.push_back(arr[i]);
      i++;
    }
    if (arr[i] > arr[j])
    {
      temp.push_back(arr[j]);
      j++;
    }
  }

  while (i <= mid)
  {
    temp.push_back(arr[i]);
    i++;
  }

  while (j <= high)
  {
    temp.push_back(arr[j]);
    j++;
  }

  for (int i = low; i <= high; i++)
  {
    arr[i] = temp[i - low];
  }
}

void MergeSort(int arr[], int low, int high)
{
  if (low < high)
  {
    int mid = (low + high) / 2;

    MergeSort(arr, low, mid);
    MergeSort(arr, mid + 1, high);
    Merge(arr, low, mid, high);
  }
}

void InsertionSort(int arr[], int n)
{
  for (int i = 1; i < n; i++)
  {
    int key = arr[i];
    int j = i - 1;

    while (j >= 0 and arr[j] > key)
    {
      swap(arr[j], arr[j + 1]);
      --j;
    }
    arr[j + 1] = key;
  }
}

void SelectionSort(int arr[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    int minidx = i;
    for (int j = i + 1; j < n; j++)
    {
      if (arr[j] < arr[minidx])
      {
        minidx = j;
      }
    }

    if (minidx != i)
      swap(arr[i], arr[minidx]);
  }
}

void BubbleSortOpt(int arr[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    bool swapped = false;
    for (int j = 0; j < n - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        swap(arr[j], arr[j + 1]);
        swapped = true;
      }
    }

    if (!swapped)
    {
      break;
    }
  }
}

void BubbleSort(int arr[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
        swap(arr[j], arr[j + 1]);
    }
  }
}

int main()
{

  int arr[] = {6900, 76, -8900, -100, 56, -234, 0};
  int n = sizeof(arr) / sizeof(arr[0]);

  printArr(arr, n);
  BubbleSort(arr, n);
  printArr(arr, n);

  int arr2[] = {6900, 76, -8900, -100, 56, -234, 0};

  printArr(arr2, n);
  BubbleSortOpt(arr2, n);
  printArr(arr2, n);

  int arr3[] = {6900, 76, -8900, -100, 56, -234, 0};
  printArr(arr3, n);
  SelectionSort(arr3, n);
  printArr(arr3, n);

  int arr4[] = {6900, 76, -8900, -100, 56, -234, 0};
  printArr(arr4, n);
  InsertionSort(arr4, n);
  printArr(arr4, n);

  int arr5[] = {6900, 76, -8900, -100, 56, -234, 0};
  printArr(arr5, n);
  MergeSort(arr5, 0, n - 1);
  printArr(arr5, n);

  int arr6[] = {6900, 76, -8900, -100, 56, -234, 0};
  printArr(arr6, n);
  QuickSort(arr6, 0, n - 1);
  printArr(arr6, n);

  int arr7[] = {6900, 76, -8900, -100, 56, -234, 0};
  printArr(arr7, n);
  HeapSort(arr7, n);
  printArr(arr7, n);
}