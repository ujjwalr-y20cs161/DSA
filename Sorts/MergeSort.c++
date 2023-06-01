#include <bits/stdc++.h>

using namespace std;

void print(int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void swap(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}

// similar to merging different lists
void merge(int arr[], int low, int mid, int high)
{
  vector<int> temp;
  // i points left sub-array
  // j points right sub-array
  int i = low, j = mid + 1;

  while (i <= mid and j <= high)
  {
    // if left less than right, append left to temp
    if (arr[i] <= arr[j])
    {
      temp.push_back(arr[i]);
      i++;
    }
    // else if right less than left pointed element, append right ele to temp
    else
    {
      temp.push_back(arr[j]);
      j++;
    }
  }

  // append remaining left sub-array, if any
  while (i <= mid)
  {
    temp.push_back(arr[i]);
    i++;
  }
  // append remaining right sub-array,if any
  while (j <= high)
  {
    temp.push_back(arr[j]);
    j++;
  }
  // update the original array, by coping it from temp
  for (int x = low; x <= high; x++)
  {
    arr[x] = temp[x - low];
  }
}

// sorts by dividing and merging
void mergeSort(int arr[], int low, int high)
{
  if (low < high)
  {
    // dividing using mid
    int mid = (low + high) / 2;

    // left half array get sorted recursively
    mergeSort(arr, low, mid);
    // right half array
    mergeSort(arr, mid + 1, high);

    // both the arrays are merged together
    merge(arr, low, mid, high);
  }
}

int main()
{

  int arr[] = {100, -200, 30, 43, 0, -4, -67, -184};
  int n = sizeof(arr) / sizeof(arr[0]);

  print(arr, n);

  mergeSort(arr, 0, n);

  print(arr, n);
}

/*

FAQ ON MERGE SORT
=================

Q: What is Merge Sort?
A: Merge Sort is a divide-and-conquer sorting algorithm that recursively divides a list into two halves until each half contains only one element. Then, it merges the sorted halves to produce a sorted output. It is known for its efficiency and stability.

Q: How does Merge Sort work?
A: Merge Sort works by dividing the unsorted list into two halves recursively until each half contains only one element. Then, it merges the two sorted halves by comparing the elements and placing them in the correct order. This merging process is repeated until the entire list is sorted.

Q: What is the time complexity of Merge Sort?
A: The time complexity of Merge Sort is O(n log n), where "n" represents the number of elements in the list. It divides the list into halves recursively and then merges them back together, resulting in a logarithmic time complexity.

Q: Is Merge Sort a stable sorting algorithm?
A: Yes, Merge Sort is a stable sorting algorithm. Stability means that the relative order of equal elements is preserved after sorting. In Merge Sort, when merging two sorted sublists, if two elements are equal, the element from the first sublist is placed before the element from the second sublist. This ensures stability in the sorting process.

Q: What are the advantages of Merge Sort?
A: Merge Sort has several advantages:
1. It guarantees a time complexity of O(n log n), making it efficient for large lists.
2. It is a stable sorting algorithm, preserving the relative order of equal elements.
3. It is easy to implement and understand.
4. It performs well on both small and large datasets.

Q: Are there any drawbacks to using Merge Sort?
A: Merge Sort also has a few drawbacks:
1. It requires additional memory to hold the merged sublists during the merging process. This can be a concern when sorting large lists with limited memory.
2. It has a relatively high space complexity of O(n) due to the need for additional memory.
3. It may not be the best choice for small lists or lists that are already partially sorted, as the overhead of the recursive calls and merging process may outweigh the benefits.

Q: In what scenarios is Merge Sort commonly used?
A: Merge Sort is commonly used in situations where stability is important and a guaranteed worst-case time complexity of O(n log n) is desired. It is often used for sorting large datasets, external sorting where data is stored on disk, and in programming libraries or frameworks where stability is a requirement.

 */