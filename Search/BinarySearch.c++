#include <iostream>
#include <vector>
#include <algorithm>

#define endd "\n";

using namespace std;

int BinarySearch(vector<int> arr, int low, int high, int key)
{
  // Condition should be low <= high only, because in searching the single element is also considered unlike in sorting.
  if (low <= high)
  {
    int mid = (low + high) / 2;
    // cout << key << low << mid << high << endd;
    if (key == arr[mid])
      return mid;
    if (key > arr[mid])
      return BinarySearch(arr, mid + 1, high, key);
    if (key < arr[mid])
      return BinarySearch(arr, low, mid - 1, key);
  }
  // returns -1 if not found.
  return -1;
}

int main()
{

  vector<int> arr = {10, 27, 23, 9, 45, -10, 45};
  sort(arr.begin(), arr.end());
  cout << BinarySearch(arr, 0, arr.size() - 1, 42) << endd;
}