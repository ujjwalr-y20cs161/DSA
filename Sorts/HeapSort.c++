#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}

void Heapify(int arr[], int n, int i)
{
  // root node
  int large = i;
  // left child
  int left = 2 * i + 1;
  // right child
  int right = 2 * i + 2;

  // if left child exists and greater than root,swap
  if (left < n and arr[left] > arr[large])
  {
    large = left;
  }
  // if right child exists and greater than root,swap
  if (right < n and arr[right] > arr[large])
  {
    large = right;
  }
  // swapping happens here
  if (large != i)
  {
    swap(arr[i], arr[large]);
    // after swapping large represents the child of the root
    // build a heap of the sub-tree[swapped child and it's sub-tree]
    Heapify(arr, n, large);
  }
}

// Heapsort works by building a max-heap and deleting the top[max] node and ?
// doing it repeatively until no element left
void HeapSort(int arr[], int n)
{
  // building max-heap, starts from (n/2-1)-> last non-leaf [last sub-tree],
  // starts there are moves up to build the whole tree
  for (int i = n / 2 - 1; i >= 0; i--)
  {
    Heapify(arr, n, i);
  }

  // repeatedly delete the max node [replace the last element with max(first)
  // element and reduce the size(i takes care of reducing size)]
  for (int i = n - 1; i >= 0; i--)
  {
    swap(arr[0], arr[i]);
    // Bulid Heap again with one less node
    Heapify(arr, i, 0);
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

  int arr[] = {100, -300, 240, 690, -34, -483, 0};
  int n = sizeof(arr) / sizeof(arr[0]);

  print(arr, n);

  HeapSort(arr, n);

  print(arr, n);
}

/*
PROPERTIES OF HS
================

1. Heapsort is an in-place sorting algorithm that uses a binary heap data structure.
2. It has a worst-case time complexity of O(n log n) and is efficient for large datasets.
3. Heapsort is not stable but has a predictable performance and guarantees a sorted output.
4. It requires additional space for the heap structure but has a space complexity of O(1) for the sorting process.
5. Heapsort is not affected by the initial order of the elements, making it suitable for a wide range of input scenarios.
6. It works by building a max-heap, repeatedly extracting the maximum element, and placing it in the sorted portion.
7. The max-heap property ensures that the largest element is always at the root of the heap.
8. Heapsort can be used for both ascending and descending order sorting by constructing a min-heap instead of a max-heap.
9. It is commonly used as a component in priority queues and heap-based data structures.
10. Heapsort has a relatively high constant factor compared to other sorting algorithms, making it slower for small and medium-sized datasets.


FAQ ON HEAPSORT
===============

Q: What is Heap Sort?
A: Heap Sort is a comparison-based sorting algorithm that uses the binary heap data structure. It involves building a max-heap from the input array and repeatedly extracting the maximum element from the heap and placing it at the end of the sorted portion of the array.

Q: How does Heap Sort work?
A: Heap Sort works by first building a max-heap from the input array. Once the max-heap is constructed, the maximum element (located at the root) is swapped with the last element in the unsorted portion of the array. The size of the heap is reduced by one, and the heapify operation is applied to the root to restore the max-heap property. This process is repeated until the entire array is sorted.

Q: What is the time complexity of Heap Sort?
A: The time complexity of Heap Sort is O(n log n), where "n" represents the number of elements in the input array. Both the construction of the initial max-heap and the repeated heapify operations take O(n log n) time.

Q: Is Heap Sort a stable sorting algorithm?
A: No, Heap Sort is not inherently stable. While the construction of the max-heap may reorder elements, the swapping and heapify operations during the sorting process do not guarantee the preservation of the relative order of equal elements. Hence, the stability of Heap Sort depends on how the algorithm is implemented.

Q: What are the advantages of Heap Sort?
A: Heap Sort has several advantages:
1. It has a worst-case time complexity of O(n log n) and is efficient for large datasets.
2. It has a space complexity of O(1) since it performs sorting in-place, without requiring additional memory.
3. It is not affected by the initial order of the elements, making it suitable for a wide range of input scenarios.
4. It is easy to implement and has a predictable performance.

Q: Are there any drawbacks to using Heap Sort?
A: Heap Sort also has a few drawbacks:
1. It is not a stable sorting algorithm by default, as mentioned earlier.
2. It has a relatively high constant factor in its time complexity, making it slower in practice than some other sorting algorithms like Quick Sort for small and medium-sized datasets.
3. It requires the use of additional data structures (heaps) and may incur overhead in terms of memory usage and implementation complexity.

Q: In what scenarios is Heap Sort commonly used?
A: Heap Sort is commonly used in scenarios where a guaranteed worst-case time complexity is required, especially for large datasets. It is used in operating systems, programming languages, and various applications where deterministic performance is essential. Additionally, Heap Sort is used as a component in other algorithms, such as priority queues and heap-based data structures.

 */