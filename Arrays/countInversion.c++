/*
Problem: Count inversions in an array

Statement:
=>Given an array of N integers, count the inversion of the array (using merge-sort).

What is an inversion of an array? Definition: for all i & j < size of array, if i < j then you have to find pair (A[i],A[j]) such that A[j] < A[i].

LINK::https://www.codingninjas.com/codestudio/problems/number-of-inversions_6840276

Companies:

Walmart
Adobe
Facebook
Flipkart
Netflix
Google
Amazon
Tekion-corp
CRED
Meesho
Swiggy
Dream11
InMobi
Oyo
PayTM

*/
#include <bits/stdc++.h>
#define endd
using namespace std;

int merge(vector<int> &arr, int low, int mid, int high)
{

  vector<int> temp;
  int i = low, j = mid + 1, count = 0;

  while (i <= mid and j <= high)
  {
    if (arr[i] <= arr[j])
    {
      temp.push_back(arr[i]);
      i++;
    }
    else
    {
      temp.push_back(arr[j]);
      j++;

      // counts the number of inversions
      count += (mid - i + 1);
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

  for (int x = low; x <= high; x++)
  {
    arr[x] = temp[x - low];
  }

  return count;
}

int mergeSort(vector<int> &arr, int low, int high)
{
  int count = 0;
  if (low < high)
  {
    int mid = (low + high) / 2;

    count += mergeSort(arr, low, mid);
    count += mergeSort(arr, mid + 1, high);
    count += merge(arr, low, mid, high);
  }
  return count;
}

int numberOfInversions(vector<int> &a, int n)
{
  // Write your code here.
  return mergeSort(a, 0, n - 1);
}

// complexity: O(nlogn) time and O(n) space