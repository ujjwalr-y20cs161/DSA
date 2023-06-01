#include <bits/stdc++.h>

using namespace std;

int n;

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

// parition takes array and sorts one element and returns the position of the sorted element in the array
int partition(int arr[], int low, int high)
{
  // select the first element as pivot
  int pivot = arr[low];

  // now we sort the pivot now!
  int i = low, j = high;

  while (i < j)
  {

    // i searches for an element greater than pivot and stops at it
    while (arr[i] <= pivot and i < high)
      i++;

    // j searches for an element less than pivot and stops at it
    while (arr[j] > pivot and j >= low)
      j--;

    // if i and j doesn't cross yet, we swap the elements
    if (i < j)
      swap(arr[i], arr[j]);

    print(arr, n);
  }
  // j at the end, points to the position that's correct for the pivot, hence we swap!
  swap(arr[low], arr[j]);
  // return the position:
  return j;
}

void quickSort(int arr[], int low, int high)
{

  if (low < high)
  {
    // find the position that's already sorted
    int p = partition(arr, low, high);
    // now sort recursively the remaining parts namely: left partiton
    quickSort(arr, low, p - 1);
    // right partition
    quickSort(arr, p + 1, high);
  }
}

int main()
{
  int arr[] = {6900, 76, -8900, -100, 56, -234, 0};
  n = sizeof(arr) / sizeof(arr[0]);

  print(arr, n);
  // Careful with the low and high values : high should be "n-1" not "n"
  quickSort(arr, 0, n - 1);

  print(arr, n);
}

/*

FAQ ON QUICK SORT
=================

**Q: What is QuickSort?**
A: QuickSort is a sorting algorithm that follows the divide-and-conquer approach.
 It selects a pivot element and partitions the other elements into two sub-arrays based on whether they are smaller or larger than the pivot. The sub-arrays are then recursively sorted.


**Q: How does QuickSort work?**
A: QuickSort works by selecting a pivot element, rearranging the array so that all elements smaller than
 the pivot are placed before it, and all elements greater than the pivot are placed after it. This process is known as partitioning. The algorithm then recursively applies the partitioning step to the sub-arrays until the entire array is sorted.



**Q: What is the time complexity of QuickSort?**
A: The average time complexity of QuickSort is O(n log n), where 'n' represents the number of elements in the array. In the best case, the time complexity can also be O(n log n), but in the worst case, it can be O(n^2). However, the worst-case scenario is rare and can be avoided by using a randomized pivot selection or other techniques.

**Q: What is the space complexity of QuickSort?**
A: The space complexity of QuickSort is O(log n) in the average and best cases, as the algorithm uses recursive calls that require additional space on the call stack. In the worst case, where the partitioning is highly unbalanced, the space complexity can be O(n).

**Q: What are the advantages of QuickSort?**
A: QuickSort has several advantages, including:
1. Efficiency: QuickSort has good average time complexity, making it efficient for large datasets.
2. In-place sorting: QuickSort sorts the array in-place, requiring minimal additional memory.
3. Cache efficiency: QuickSort's partitioning step tends to work on small portions of the array, making it cache-friendly and efficient in practice.

**Q: What are the disadvantages of QuickSort?**
A: QuickSort also has some limitations, such as:
1. Worst-case time complexity: In the worst-case scenario, when the pivot selection is consistently poor, QuickSort's time complexity can degrade to O(n^2), making it inefficient.
2. Lack of stability: QuickSort is not a stable sorting algorithm, meaning that the relative order of equal elements may change during the sorting process.

**Q: When is QuickSort a good choice?**
A: QuickSort is a good choice when:
1. Average-case performance matters more than worst-case performance.
2. The dataset is large, as QuickSort's average time complexity is efficient for large inputs.
3. In-place sorting is desired to minimize memory usage.
4. Cache efficiency is important due to its partitioning step.

**Q: Are there variations of QuickSort?**
A: Yes, there are variations of QuickSort that aim to improve its worst-case behavior or optimize its performance for specific scenarios. Some variations include Randomized QuickSort, Dual-Pivot QuickSort, and IntroSort (which switches to a different sorting algorithm for small sub-arrays to avoid worst-case scenarios).
 */