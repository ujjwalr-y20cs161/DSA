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

/*

Binary search can be categorized as a Divide and Conquer algorithm. The Divide and Conquer paradigm involves breaking down a problem into smaller subproblems, solving each subproblem independently, and then combining the solutions to obtain the final result.

FAQ:
====

* What is binary search?

Binary search is an efficient algorithm for finding a specific value in a sorted array or list by repeatedly dividing the search space in half.


* How does binary search work?

Binary search starts by comparing the target value with the middle element of the sorted array. If the target is equal to the middle element, the search is successful. If the target is less than the middle element, the search continues on the lower half of the array. If the target is greater, the search continues on the upper half. This process is repeated until the target is found or the search space is exhausted.

* What are the time and space complexities of binary search?

Binary search has a time complexity of O(log n) since it divides the search space in half at each step. The space complexity is O(1) because it doesn't require additional space proportional to the input size.

* Does binary search work only on sorted arrays?

Yes, binary search is applicable only to sorted arrays or lists. If the input is not sorted, binary search cannot guarantee correct results.

* What happens if the array is not sorted for binary search?

If the array is not sorted, binary search cannot provide accurate results. In such cases, you might need to consider other search algorithms like linear search.

* Can binary search be applied to other data structures besides arrays?

Although binary search is commonly used with arrays, it can be adapted to other data structures with similar properties, such as binary search trees.

* Are there any variations or edge cases of binary search to be aware of?

Yes, some variations of binary search include finding the leftmost or rightmost occurrence of a target value, finding the closest element, or performing binary search in a rotated sorted array.

* How can you handle situations where the array is too large to fit in memory?

Binary search assumes random access to elements, which might not be possible if the array is too large to fit in memory. In such cases, you would need to consider alternative strategies or algorithms that handle external storage or streaming.

* What are the common mistakes to avoid while implementing binary search?

Some common mistakes include incorrect calculation of mid indices, not updating the search space correctly, and not considering the termination conditions carefully.

 */